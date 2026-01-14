/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:40:42 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/08 08:47:59 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token_with_flags(t_token_kind kind, t_token *cur,
								char *str, int flags)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->kind = kind;
	if (str)
	{
		token->word = ft_calloc(1, sizeof(t_word));
		if (token->word)
		{
			token->word->str = str;
			token->word->flags = flags;
		}
	}
	cur->next = token;
	return (token);
}

t_token	*create_token(t_token_kind kind, t_token *cur, char *str)
{
	return (create_token_with_flags(kind, cur, str, 0));
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	if (!tokens)
		return ;
	while (tokens)
	{
		tmp = tokens->next;
		free_word(tokens->word);
		tokens = tmp;
	}
}

size_t	token_list_size(t_token *token)
{
	size_t	size;

	size = 0;
	while (token)
	{
		token = token->next;
		size++;
	}
	return (size);
}
