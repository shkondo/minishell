/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:33:10 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/27 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "builtin.h"
# include "command.h"
# include "executor.h"
# include "libft.h"
# include "make_cmd.h"
# include "subst.h"
# include "variables.h"

# define BUFFER_SIZE 1024
# define TOK_BUFSIZE 64
# define TOK_DELIM " \t\r\n\a"

typedef struct s_shell
{
	t_env	*env_list;
	int		exit_status;
	char	**envp;
}			t_shell;

int			is_space(char c);
int			is_metachar(char c);

int			is_quote(char c);
int			skip_quoted(char *line, int *pos);
int			calc_word_flags(char *str);

void		parser_init(t_parser *p, t_token *tokens);
void		parser_advance(t_parser *p);
int			parser_check(t_parser *p, t_token_kind kind);
void		parser_error(t_parser *p, char *token);

t_cmd		*parse_simple_command(t_parser *p);

void		parse_redirection(t_parser *p, t_cmd *cmd);

#endif
