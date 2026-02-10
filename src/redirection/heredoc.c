/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/27 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "redir.h"
#include "signals.h"
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	write_to_pipe(int fd, char *line)
{
	ft_putendl_fd(line, fd);
	return (0);
}

static int	read_heredoc_lines(int fd, char *delimiter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			ft_putstr_fd("minishell: warning: ", STDERR_FILENO);
			ft_putstr_fd("here-document delimited by EOF\n", STDERR_FILENO);
			break ;
		}
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			free(line);
			break ;
		}
		write_to_pipe(fd, line);
		free(line);
		if (g_signal_received)
			return (-1);
	}
	return (0);
}

int	do_heredoc(t_redir *redir, t_shell *shell)
{
	int	pipefd[2];

	(void)shell;
	if (pipe(pipefd) == -1)
		return (-1);
	setup_signals_heredoc();
	g_signal_received = 0;
	if (read_heredoc_lines(pipefd[1], redir->file) == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		setup_signals_interactive();
		return (-1);
	}
	close(pipefd[1]);
	setup_signals_interactive();
	redir->fd = pipefd[0];
	return (0);
}
