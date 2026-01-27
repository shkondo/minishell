/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:44:52 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/27 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBST_H
# define SUBST_H

# include "command.h"
# include "variables.h"

struct	s_shell;

char	*expand_word(char *str, int flags, struct s_shell *shell);
char	**expand_to_argv(t_token *tokens, struct s_shell *shell);
char	*expand_redir_file(char *str, int flags, struct s_shell *shell);

char	*expand_word_internal(char *str, struct s_shell *shell);

char	*param_expand(char *str, int *i, struct s_shell *shell);

char	*dequote_string(char *str);

void	expand_command(t_cmd *cmd, struct s_shell *shell);

#endif
