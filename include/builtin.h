/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/02/11 05:27:50 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "variables.h"
# include <stdio.h>

typedef struct s_shell	t_shell;

int						is_builtin(char *cmd);
int						is_builtin_cmd(char **argv);
int						exec_builtin(char **argv, t_shell *shell);

int						builtin_echo(char **argv);
int						builtin_cd(char **argv, t_shell *shell);
int						builtin_pwd(void);
int						builtin_export(char **argv, t_shell *shell);
int						builtin_unset(char **argv, t_shell *shell);
int						builtin_env(t_shell *shell);
int						builtin_exit(char **argv, t_shell *shell);

#endif
