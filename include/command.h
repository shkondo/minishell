/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:29:53 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/15 00:22:18 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <stddef.h>

# define W_HASDOLLAR 0X01
# define W_QUOTED 0x02
# define W_SINGLEQUOTE 0x04
# define W_DOUBLEQUOTE 0x08
# define W_EXPANDED 0x10

# define ERR_SYNTAX 2
# define ERR_PERM 126
# define ERR_CMD 127

typedef enum e_token_kind
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND,
	TOKEN_EOF
}					t_token_kind;

typedef struct s_word
{
	char			*str;
	int				flags;
}					t_word;

typedef struct s_token
{
	t_word			*word;
	t_token_kind	kind;
	struct s_token	*next;
}					t_token;

typedef struct s_redir
{
	t_token_kind	type;
	char			*file;
	int				fd;
	struct s_redir	*next;
}					t_redir;

typedef struct s_cmd
{
	char			**argv;
	t_redir			*redirects;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_parser
{
	t_token			*cur;
	int				error;
	char			*err_token;
}					t_parser;

t_word				*create_word(char *str, int flags);
t_word				*copy_word(t_word *word);
void				free_word(t_word *word);

t_token				*create_token(t_token_kind kind, t_token *cur, char *str);
t_token				*create_token_with_flags(t_token_kind kind, t_token *cur,
						char *str, int flags);
t_token				*copy_tokens(t_token *tokens);
void				free_tokens(t_token *tokens);
size_t				token_list_size(t_token *token);

t_token				*read_token_word(char *line, int *pos, t_token *cur);
t_token				*tokenize(char *line);

t_cmd				*parse_pipeline(t_token *tokens);

void				dispose_command(t_cmd *cmd);
void				dispose_redirects(t_redir *redir);

#endif
