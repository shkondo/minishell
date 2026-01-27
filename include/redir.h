/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/27 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "command.h"

typedef struct s_shell	t_shell;

int						setup_redirections(t_redir *redir);
int						do_redirection(t_redir *redir);
void					restore_fds(int saved_stdin, int saved_stdout);
int						save_fds(int *saved_stdin, int *saved_stdout);

int						do_heredoc(t_redir *redir, t_shell *shell);

#endif
