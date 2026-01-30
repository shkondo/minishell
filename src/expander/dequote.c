/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*append_char(char *str, char c)
{
	char	*result;
	int		len;

	if (!str)
	{
		result = malloc(2);
		if (!result)
			return (NULL);
		result[0] = c;
		result[1] = '\0';
		return (result);
	}
	len = ft_strlen(str);
	result = malloc(len + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, len + 1);
	result[len] = c;
	result[len + 1] = '\0';
	free(str);
	return (result);
}

static char	*process_single_quote(char *str, int *i, char *result)
{
	(*i)++;
	while (str[*i] && str[*i] != '\'')
	{
		result = append_char(result, str[*i]);
		(*i)++;
	}
	if (str[*i] == '\'')
		(*i)++;
	return (result);
}

static char	*process_double_quote(char *str, int *i, char *result)
{
	(*i)++;
	while (str[*i] && str[*i] != '"')
	{
		result = append_char(result, str[*i]);
		(*i)++;
	}
	if (str[*i] == '"')
		(*i)++;
	return (result);
}

char	*dequote_string(char *str)
{
	char	*result;
	int		i;

	if (!str)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			result = process_single_quote(str, &i, result);
		else if (str[i] == '"')
			result = process_double_quote(str, &i, result);
		else
		{
			result = append_char(result, str[i]);
			i++;
		}
		if (!result)
			return (NULL);
	}
	return (result);
}
