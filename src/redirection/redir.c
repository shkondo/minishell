/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/27 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redir.h"
#include <fcntl.h>
#include <unistd.h>

static void	print_redir_error(char *file)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putendl_fd(": No such file or directory", STDERR_FILENO);
}

static int	redir_input(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_RDONLY);
	if (fd == -1)
	{
		print_redir_error(redir->file);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

static int	redir_output(t_redir *redir)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (redir->type == TOKEN_APPEND)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(redir->file, flags, 0644);
	if (fd == -1)
	{
		print_redir_error(redir->file);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	do_redirection(t_redir *redir)
{
	if (redir->type == TOKEN_REDIR_IN)
		return (redir_input(redir));
	else if (redir->type == TOKEN_REDIR_OUT || redir->type == TOKEN_APPEND)
		return (redir_output(redir));
	return (0);
}

int	setup_redirections(t_redir *redir)
{
	while (redir)
	{
		if (redir->type != TOKEN_HEREDOC)
		{
			if (do_redirection(redir) == -1)
				return (-1);
		}
		redir = redir->next;
	}
	return (0);
}
