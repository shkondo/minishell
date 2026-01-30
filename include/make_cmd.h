/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_CMD_H
# define MAKE_CMD_H

# include "command.h"

/* make_cmd.c */
t_cmd	*make_simple_command(void);
t_redir	*make_redirection(t_token_kind type, char *file);
t_cmd	*command_connect(t_cmd *cmd1, t_cmd *cmd2);

#endif
