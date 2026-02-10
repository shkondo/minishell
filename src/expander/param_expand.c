/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_var_char(char c, int first)
{
	if (first)
		return (ft_isalpha(c) || c == '_');
	return (ft_isalnum(c) || c == '_');
}

static char	*extract_var_name(char *str, int *i)
{
	int		start;
	int		len;
	char	*name;

	start = *i;
	len = 0;
	while (str[*i] && is_valid_var_char(str[*i], len == 0))
	{
		(*i)++;
		len++;
	}
	if (len == 0)
		return (NULL);
	name = ft_substr(str, start, len);
	return (name);
}

static char	*expand_variable(char *str, int *i, t_env *env_list)
{
	char	*name;
	char	*value;
	char	*result;

	name = extract_var_name(str, i);
	if (!name)
		return (ft_strdup(""));
	value = get_var_value(name, env_list);
	free(name);
	if (value)
		result = ft_strdup(value);
	else
		result = ft_strdup("");
	return (result);
}

char	*param_expand(char *str, int *i, t_shell *shell)
{
	char	*result;

	(*i)++;
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(shell->exit_status));
	}
	if (is_valid_var_char(str[*i], 1))
	{
		result = expand_variable(str, i, shell->env_list);
		return (result);
	}
	return (ft_strdup("$"));
}
