# `env` 引数付き実行の不具合と修正

## 1. 症状

以下を実行したとき、`test=test` が表示されない。

```bash
env test=test | grep "^test="
```

期待値:

- `test=test` が出力される

実際:

- 何も出力されない

---

## 2. 原因

### 2.1 単体実行経路 (`execute_simple_command`)

`src/executor/execute_cmd.c` では、`is_builtin("env")` が常に真となり、
`env` を無条件にビルトイン実行していた。

そのため `env test=test` が「外部 `env` の引数付き実行」ではなく、
「ビルトイン `env` の現在環境表示」として処理されていた。

### 2.2 パイプライン実行経路 (`exec_cmd_or_builtin`)

`src/pipeline/pipe_utils.c` でも同様に、`env` を無条件でビルトイン実行
していた。

結果として、`env test=test | grep ...` の左辺が外部 `env` にならず、
一時環境変数 `test=test` が左辺プロセスの出力に含まれなかった。

---

## 3. 実施した修正

### 3.1 `src/executor/execute_cmd.c`

`env` かつ引数あり (`cmd->argv[1] != NULL`) の場合は、
ビルトイン扱いを外して外部コマンド実行へフォールバックするよう変更。

要点:

- 変更前: `env` は常に `exec_builtin_with_redir()` へ
- 変更後: `env` + 引数ありのときだけ `builtin = 0`

### 3.2 `src/pipeline/pipe_utils.c`

パイプライン側の `exec_cmd_or_builtin()` にも同じ分岐を適用。

要点:

- 変更前: `if (is_builtin(cmd->argv[0])) exit(exec_builtin(...))`
- 変更後: `env` + 引数ありならビルトイン扱いせず外部 `env` を実行

---

## 4. 挙動の整理（bash互換）

- `env test=test` / `env test=test | ...`
  - 一時環境として `test=test` を付与して対象コマンドを実行
  - シェル本体の永続環境には残らない
- `export test=test`
  - シェル環境に永続化され、以後の `env` に表示される

---

## 5. 検証結果

確認済み:

- `env test=test | grep "^test="` で `test=test` が表示される
- `env | grep "^test="` では表示されない（未 export のため）
- `export test=test` 後は `env | grep "^test="` で表示される

品質確認:

- `norminette`（修正対象ファイル）: OK
- `make`: 成功

