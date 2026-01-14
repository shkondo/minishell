/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_redir_token_str(t_token_kind kind)
{
	if (kind == TOKEN_REDIR_IN)
		return ("<");
	if (kind == TOKEN_REDIR_OUT)
		return (">");
	if (kind == TOKEN_APPEND)
		return (">>");
	if (kind == TOKEN_HEREDOC)
		return ("<<");
	return ("newline");
}

static void	add_redir_to_cmd(t_cmd *cmd, t_redir *redir)
{
	t_redir	*tmp;

	if (!cmd->redirects)
	{
		cmd->redirects = redir;
		return ;
	}
	tmp = cmd->redirects;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = redir;
}

void	parse_redirection(t_parser *p, t_cmd *cmd)
{
	t_token_kind	type;
	char			*file;
	t_redir			*redir;

	type = p->cur->kind;
	parser_advance(p);
	if (!p->cur || p->cur->kind != TOKEN_WORD)
	{
		if (p->cur && p->cur->kind != TOKEN_EOF)
			parser_error(p, get_redir_token_str(p->cur->kind));
		else
			parser_error(p, "newline");
		return ;
	}
	file = ft_strdup(p->cur->word->str);
	if (!file)
		return ;
	redir = make_redirection(type, file);
	if (!redir)
	{
		free(file);
		return ;
	}
	add_redir_to_cmd(cmd, redir);
	parser_advance(p);
}
