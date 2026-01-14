/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser_init(t_parser *p, t_token *tokens)
{
	p->cur = tokens;
	p->error = 0;
	p->err_token = NULL;
}

void	parser_advance(t_parser *p)
{
	if (p->cur && p->cur->kind != TOKEN_EOF)
		p->cur = p->cur->next;
}

int	parser_check(t_parser *p, t_token_kind kind)
{
	if (!p->cur)
		return (0);
	return (p->cur->kind == kind);
}

void	parser_error(t_parser *p, char *token)
{
	if (p->error)
		return ;
	p->error = 1;
	p->err_token = token;
}
