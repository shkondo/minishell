/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subst_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*append_str(char *s1, char *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*append_char_to_str(char *str, char c)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = '\0';
	return (append_str(str, buf));
}

static char	*expand_in_dquote(char *str, int *i, t_shell *shell, char *result)
{
	char	*expanded;

	(*i)++;
	while (str[*i] && str[*i] != '"')
	{
		if (str[*i] == '$' && str[*i + 1])
		{
			expanded = param_expand(str, i, shell);
			result = append_str(result, expanded);
			free(expanded);
		}
		else
		{
			result = append_char_to_str(result, str[*i]);
			(*i)++;
		}
	}
	if (str[*i] == '"')
		(*i)++;
	return (result);
}

static char	*skip_single_quote(char *str, int *i, char *result)
{
	(*i)++;
	while (str[*i] && str[*i] != '\'')
	{
		result = append_char_to_str(result, str[*i]);
		(*i)++;
	}
	if (str[*i] == '\'')
		(*i)++;
	return (result);
}

char	*expand_word_internal(char *str, t_shell *shell)
{
	char	*result;
	char	*expanded;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			result = skip_single_quote(str, &i, result);
		else if (str[i] == '"')
			result = expand_in_dquote(str, &i, shell, result);
		else if (str[i] == '$' && str[i + 1])
		{
			expanded = param_expand(str, &i, shell);
			result = append_str(result, expanded);
			free(expanded);
		}
		else
		{
			result = append_char_to_str(result, str[i]);
			i++;
		}
	}
	return (result);
}
