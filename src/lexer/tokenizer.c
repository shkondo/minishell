/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:00:03 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/08 08:52:56 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*read_token_word(char *line, int *pos, t_token *cur)
{
	int		start;
	int		flags;
	char	*str;

	start = *pos;
	while (line[*pos] && !is_space(line[*pos]) && !is_metachar(line[*pos]))
	{
		if (is_quote(line[*pos]))
		{
			if (skip_quoted(line, pos) == -1)
				return (NULL);
		}
		else
			(*pos)++;
	}
	str = ft_substr(line, start, *pos - start);
	if (!str)
		return (NULL);
	flags = calc_word_flags(str);
	return (create_token_with_flags(TOKEN_WORD, cur, str, flags));
}

t_token	*read_operator(char *line, int *pos, t_token *cur)
{
	t_token_kind	kind;

	if (line[*pos] == '|')
		kind = TOKEN_PIPE;
	else if (line[*pos] == '<' && line[*pos + 1] == '<')
	{
		kind = TOKEN_HEREDOC;
		(*pos)++;
	}
	else if (line[*pos] == '<')
		kind = TOKEN_REDIR_IN;
	else if (line[*pos] == '>' && line[*pos + 1] == '>')
	{
		kind = TOKEN_APPEND;
		(*pos)++;
	}
	else
		kind = TOKEN_REDIR_OUT;
	(*pos)++;
	return (create_token(kind, cur, NULL));
}

static t_token	*syntax_error_quote(t_token *tokens)
{
	ft_putstr_fd("minishell: syntax error: unclosed quote\n", 2);
	free_tokens(tokens);
	return (NULL);
}

t_token	*tokenize(char *line)
{
	int		pos;
	t_token	head;
	t_token	*cur;

	pos = 0;
	ft_memset(&head, 0, sizeof(head));
	cur = &head;
	while (line[pos])
	{
		while (line[pos] && is_space(line[pos]))
			pos++;
		if (!line[pos])
			break ;
		if (is_metachar(line[pos]))
			cur = read_operator(line, &pos, cur);
		else
			cur = read_token_word(line, &pos, cur);
		if (!cur)
			return (syntax_error_quote(head.next));
	}
	create_token(TOKEN_EOF, cur, NULL);
	return (head.next);
}
