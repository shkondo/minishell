/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:40:42 by shkondo           #+#    #+#             */
/*   Updated: 2025/12/26 20:23:16 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(t_word *word, t_token *next);

t_token	*token_add_back(t_token **lst, t_word *word);

t_token	*copy_tokens(t_token *tokens);

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
