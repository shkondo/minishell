/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/07 09:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

static int	find_closing_quote(char *line, int start, char quote)
{
	int	i;

	i = start;
	while (line[i])
	{
		if (line[i] == quote)
			return (i);
		i++;
	}
	return (-1);
}

int	skip_quoted(char *line, int *pos)
{
	char	quote;
	int		close_pos;

	quote = line[*pos];
	close_pos = find_closing_quote(line, *pos + 1, quote);
	if (close_pos == -1)
		return (-1);
	*pos = close_pos + 1;
	return (0);
}

static int	has_dollar_in_dquote(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && is_quote(str[i]))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		else if (str[i] == '$' && quote != '\'')
			return (1);
		i++;
	}
	return (0);
}

int	calc_word_flags(char *str)
{
	int	flags;
	int	i;

	flags = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			flags |= (W_QUOTED | W_SINGLEQUOTE);
		else if (str[i] == '"')
			flags |= (W_QUOTED | W_DOUBLEQUOTE);
		i++;
	}
	if (has_dollar_in_dquote(str))
		flags |= W_HASDOLLAR;
	return (flags);
}
