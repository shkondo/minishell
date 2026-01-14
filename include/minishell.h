/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:33:10 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/04 22:18:10 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtin.h"
# include "command.h"
# include "executor.h"
# include "make_cmd.h"
# include "variables.h"
# include "subst.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <stdbool.h>
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
	t_env	*env_list;
	int		exit_status;
	char	**envp;
}			t_shell;

/* main.c - 内部関数のため宣言不要 */

int			ft_cd(char **args);
int			ft_help(char **args);
int			ft_exit(char **args);

int			is_space(char c);
int			is_metachar(char c);

/* quote_utils.c */
int			is_quote(char c);
int			skip_quoted(char *line, int *pos);
int			calc_word_flags(char *str);

/* parser_utils.c */
void		parser_init(t_parser *p, t_token *tokens);
void		parser_advance(t_parser *p);
int			parser_check(t_parser *p, t_token_kind kind);
void		parser_error(t_parser *p, char *token);

/* parse_command.c */
t_cmd		*parse_simple_command(t_parser *p);

/* parse_redirect.c */
void		parse_redirection(t_parser *p, t_cmd *cmd);

#endif
