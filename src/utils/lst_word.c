/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:34 by shkondo           #+#    #+#             */
/*   Updated: 2025/12/25 18:39:39 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*create_word(char *str, int type);

t_word	*copy_word(t_word *word);

void	free_word(t_word *word);

void	set_word_flags(t_word *word, char *str);
