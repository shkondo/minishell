/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_syntax_error(char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
}

static char	*get_error_token(t_parser *p)
{
	if (!p->cur || p->cur->kind == TOKEN_EOF)
		return ("newline");
	if (p->cur->kind == TOKEN_PIPE)
		return ("|");
	if (p->cur->kind == TOKEN_REDIR_IN)
		return ("<");
	if (p->cur->kind == TOKEN_REDIR_OUT)
		return (">");
	if (p->cur->kind == TOKEN_APPEND)
		return (">>");
	if (p->cur->kind == TOKEN_HEREDOC)
		return ("<<");
	if (p->cur->word && p->cur->word->str)
		return (p->cur->word->str);
	return ("newline");
}

t_cmd	*parse_pipeline(t_token *tokens)
{
	t_parser	p;
	t_cmd		*first;
	t_cmd		*cmd;

	parser_init(&p, tokens);
	if (parser_check(&p, TOKEN_EOF))
		return (NULL);
	first = parse_simple_command(&p);
	if (p.error)
		return (print_syntax_error(p.err_token), dispose_command(first), NULL);
	while (parser_check(&p, TOKEN_PIPE))
	{
		parser_advance(&p);
		cmd = parse_simple_command(&p);
		if (p.error)
			return (print_syntax_error(p.err_token),
				dispose_command(first), NULL);
		first = command_connect(first, cmd);
	}
	if (!parser_check(&p, TOKEN_EOF))
		return (print_syntax_error(get_error_token(&p)),
			dispose_command(first), NULL);
	return (first);
}
