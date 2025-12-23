/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:33:10 by shkondo           #+#    #+#             */
/*   Updated: 2025/12/23 00:44:51 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtin.h"
# include "executor.h"
# include "lexer.h"
# include "libft.h"
# include "parser.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define BUFFER_SIZE 1024
# define TOK_BUFSIZE 64
# define TOK_DELIM " \t\r\n\a"

typedef struct s_shell
{
	char	*envp;
	int		exit_status;
}

void		msh_loop(void);
char		*msh_read_line(void);

int			ft_cd(char **args);
int			ft_help(char **args);
int			ft_exit(char **args);

#endif
