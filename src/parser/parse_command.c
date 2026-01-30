/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_redirect(t_token_kind kind)
{
	return (kind == TOKEN_REDIR_IN || kind == TOKEN_REDIR_OUT
		|| kind == TOKEN_HEREDOC || kind == TOKEN_APPEND);
}

static int	count_words(t_parser *p)
{
	t_token	*tmp;
	int		count;

	tmp = p->cur;
	count = 0;
	while (tmp && tmp->kind != TOKEN_EOF && tmp->kind != TOKEN_PIPE)
	{
		if (tmp->kind == TOKEN_WORD)
			count++;
		else if (is_redirect(tmp->kind) && tmp->next)
			tmp = tmp->next;
		tmp = tmp->next;
	}
	return (count);
}

static int	add_word_to_argv(t_parser *p, t_cmd *cmd, int *idx)
{
	if (!p->cur->word || !p->cur->word->str)
		return (0);
	cmd->argv[*idx] = ft_strdup(p->cur->word->str);
	if (!cmd->argv[*idx])
		return (0);
	(*idx)++;
	parser_advance(p);
	return (1);
}

t_cmd	*parse_simple_command(t_parser *p)
{
	t_cmd	*cmd;
	int		argc;
	int		idx;

	if (parser_check(p, TOKEN_PIPE) || parser_check(p, TOKEN_EOF))
		return (parser_error(p, "|"), NULL);
	cmd = make_simple_command();
	argc = count_words(p);
	cmd->argv = ft_calloc(argc + 1, sizeof(char *));
	idx = 0;
	while (p->cur && p->cur->kind != TOKEN_EOF && p->cur->kind != TOKEN_PIPE)
	{
		if (p->cur->kind == TOKEN_WORD)
			add_word_to_argv(p, cmd, &idx);
		else if (is_redirect(p->cur->kind))
			parse_redirection(p, cmd);
		if (p->error)
			return (dispose_command(cmd), NULL);
	}
	return (cmd);
}
