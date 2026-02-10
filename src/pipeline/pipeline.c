/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
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
#include <stdlib.h>
#include <sys/wait.h>

void		exec_pipe_child(t_cmd *cmd, t_shell *shell, int in_fd, int out_fd);
int			wait_for_children(int n, int last_pid);

static int	fork_cmd(t_cmd *cmd, t_shell *shell, int in_fd, int pipefd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (cmd->next)
			close(pipefd[0]);
		if (cmd->next)
			exec_pipe_child(cmd, shell, in_fd, pipefd[1]);
		else
			exec_pipe_child(cmd, shell, in_fd, STDOUT_FILENO);
	}
	return (pid);
}

static int	exec_pipe_loop(t_cmd *cmd, t_shell *shell, int *last_pid)
{
	int	pipefd[2];
	int	in_fd;
	int	n;

	in_fd = STDIN_FILENO;
	n = 0;
	while (cmd)
	{
		if (cmd->next && pipe(pipefd) == -1)
			return (-1);
		*last_pid = fork_cmd(cmd, shell, in_fd, pipefd);
		if (*last_pid == -1)
			return (-1);
		if (in_fd != STDIN_FILENO)
			close(in_fd);
		if (cmd->next)
		{
			close(pipefd[1]);
			in_fd = pipefd[0];
		}
		cmd = cmd->next;
		n++;
	}
	return (n);
}

int	execute_pipeline(t_cmd *cmd, t_shell *shell)
{
	int	last_pid;
	int	n;
	int	status;

	setup_signals_ignore();
	n = exec_pipe_loop(cmd, shell, &last_pid);
	if (n == -1)
		return (1);
	status = wait_for_children(n, last_pid);
	setup_signals_interactive();
	return (status);
}
