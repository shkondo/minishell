/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
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

int	wait_for_children(int n, int last_pid)
{
	int		status;
	int		last_status;
	pid_t	pid;
	int		i;

	last_status = 0;
	i = 0;
	while (i < n)
	{
		pid = wait(&status);
		if (pid == last_pid)
			last_status = get_exit_status(status);
		i++;
	}
	return (last_status);
}

static void	setup_pipe_fds(int in_fd, int out_fd)
{
	if (in_fd != STDIN_FILENO)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (out_fd != STDOUT_FILENO)
	{
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
}

static void	exec_cmd_or_builtin(t_cmd *cmd, t_shell *shell)
{
	char	*path;
	char	**envp;

	if (is_builtin_cmd(cmd->argv))
		exit(exec_builtin(cmd->argv, shell));
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

void	exec_pipe_child(t_cmd *cmd, t_shell *shell, int in_fd, int out_fd)
{
	setup_signals_child();
	setup_pipe_fds(in_fd, out_fd);
	if (setup_redirections(cmd->redirects) == -1)
		exit(1);
	expand_command(cmd, shell);
	exec_cmd_or_builtin(cmd, shell);
}
