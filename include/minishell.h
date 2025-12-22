/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:33:10 by shkondo           #+#    #+#             */
/*   Updated: 2025/12/22 01:45:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <libft.h>

# define BUFFER_SIZE 1024
# define TOK_BUFSIZE 64
# define TOK_DELIM " \t\r\n\a"

typedef struct s_cmd
{
	char	*cmd;
}	t_cmd;

void	msh_loop(void);
char	*msh_read_line(void);

int	ft_cd(char **args);
int ft_help(char **args);
int ft_exit(char **args);

#endif
