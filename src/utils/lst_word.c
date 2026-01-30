/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:34 by shkondo           #+#    #+#             */
/*   Updated: 2025/12/29 16:52:41 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*copy_word(t_word *word)
{
	t_word	*new_word;

	if (!word)
		return (NULL);
	new_word = malloc(sizeof(t_word));
	if (!new_word)
		return (NULL);
	new_word->str = word->str;
	return (new_word);
}

void	free_word(t_word *word)
{
	if (!word)
		return ;
	free(word->str);
	free(word);
}
