/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:44:52 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBST_H
# define SUBST_H

# include "command.h"
# include "variables.h"

struct	s_shell;

/* subst.c */
char	*expand_word(char *str, int flags, struct s_shell *shell);
char	**expand_to_argv(t_token *tokens, struct s_shell *shell);
char	*expand_redir_file(char *str, int flags, struct s_shell *shell);

/* subst_expand.c */
char	*expand_word_internal(char *str, struct s_shell *shell);

/* param_expand.c */
char	*param_expand(char *str, int *i, struct s_shell *shell);

/* dequote.c */
char	*dequote_string(char *str);

#endif
