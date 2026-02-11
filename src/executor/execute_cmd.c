/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/27 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "executor.h"
#include "libft.h"
#include "minishell.h"
#include "redir.h"
#include "signals.h"
#include "subst.h"
#include <stdlib.h>
#include <sys/wait.h>

static int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (status);
}

static void	exec_external(t_cmd *cmd, t_shell *shell)
{
	char	*path;
	char	**envp;

	setup_signals_child();
	if (setup_redirections(cmd->redirects) == -1)
		exit(1);
	path = find_command(cmd->argv[0], shell);
	if (!path)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		exit(ERR_CMD);
	}
	envp = env_list_to_envp(shell->env_list);
	execve(path, cmd->argv, envp);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putendl_fd(": Permission denied", STDERR_FILENO);
	exit(ERR_PERM);
}

static int	exec_builtin_with_redir(t_cmd *cmd, t_shell *shell)
{
	int	saved_stdin;
	int	saved_stdout;
	int	ret;

	if (save_fds(&saved_stdin, &saved_stdout) == -1)
		return (1);
	if (setup_redirections(cmd->redirects) == -1)
	{
		restore_fds(saved_stdin, saved_stdout);
		return (1);
	}
	ret = exec_builtin(cmd->argv, shell);
	restore_fds(saved_stdin, saved_stdout);
	return (ret);
}

int	execute_simple_command(t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;

	expand_command(cmd, shell);
	if (!cmd->argv || !cmd->argv[0])
		return (0);
	if (is_builtin_cmd(cmd->argv))
		return (exec_builtin_with_redir(cmd, shell));
	setup_signals_ignore();
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		exec_external(cmd, shell);
	waitpid(pid, &status, 0);
	setup_signals_interactive();
	return (get_exit_status(status));
}

int	execute(t_cmd *cmd, t_shell *shell)
{
	if (!cmd)
		return (0);
	if (cmd->next)
		return (execute_pipeline(cmd, shell));
	return (execute_simple_command(cmd, shell));
}
