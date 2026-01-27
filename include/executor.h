/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/27 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "command.h"

typedef struct s_shell	t_shell;

int						execute(t_cmd *cmd, t_shell *shell);
int						execute_simple_command(t_cmd *cmd, t_shell *shell);
int						execute_pipeline(t_cmd *cmd, t_shell *shell);

char					*find_command(char *cmd, t_shell *shell);

#endif
