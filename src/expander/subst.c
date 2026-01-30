/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 08:48:32 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_word(char *str, int flags, t_shell *shell)
{
	char	*result;

	if (!str)
		return (NULL);
	if (!(flags & W_HASDOLLAR) && !(flags & W_QUOTED))
		return (ft_strdup(str));
	result = expand_word_internal(str, shell);
	return (result);
}

static int	count_tokens(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->kind != TOKEN_EOF)
	{
		if (tokens->kind == TOKEN_WORD)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

char	**expand_to_argv(t_token *tokens, t_shell *shell)
{
	char	**argv;
	int		count;
	int		i;
	char	*expanded;

	count = count_tokens(tokens);
	argv = ft_calloc(count + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	i = 0;
	while (tokens && tokens->kind != TOKEN_EOF)
	{
		if (tokens->kind == TOKEN_WORD && tokens->word)
		{
			expanded = expand_word(tokens->word->str, tokens->word->flags,
					shell);
			argv[i++] = expanded;
		}
		tokens = tokens->next;
	}
	argv[i] = NULL;
	return (argv);
}

char	*expand_redir_file(char *str, int flags, t_shell *shell)
{
	return (expand_word(str, flags, shell));
}
