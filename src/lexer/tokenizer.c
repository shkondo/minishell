/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:00:03 by shkondo           #+#    #+#             */
/*   Updated: 2025/12/26 20:15:28 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tokenize(char *line)
{
	t_token	head;
	t_token	*cur;
	t_word	*word;

	head.next = NULL;
	cur = &head;
	while (*line)
	{
		if (is_space(*line))
		{
			line++;
			continue ;
		}
		if (is_kind(*line))
		{
			cur = create_token(word, line++);
			cur->word->str = line;
			continue ;
		}
		perror("Error");
	}
	create_token(word, line++);
	return (head.next);
}
