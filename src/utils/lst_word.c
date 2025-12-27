/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:34 by shkondo           #+#    #+#             */
/*   Updated: 2025/12/26 20:13:59 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*create_word(char *str, int kind)
{
	t_word	*new_word;

	if (!str)
		return (NULL);
	new_word = malloc(sizeof(t_word));
	if (!new_word)
		return (NULL);
	new_word->str = str;
	return (new_word);
}

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
		return (NULL);
	free(word->str);
	free(word);
}

void	set_word_flags(t_word *word, char *str);
