/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/02/11 05:27:50 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "subst.h"

static int	count_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv && argv[i])
		i++;
	return (i);
}

static char	**expand_argv(char **argv, t_shell *shell)
{
	char	**new_argv;
	int		count;
	int		i;

	count = count_argv(argv);
	new_argv = ft_calloc(count + 1, sizeof(char *));
	if (!new_argv)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_argv[i] = expand_word(argv[i], W_HASDOLLAR, shell);
		if (!new_argv[i])
			new_argv[i] = ft_strdup(argv[i]);
		i++;
	}
	return (new_argv);
}

static void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	expand_command(t_cmd *cmd, t_shell *shell)
{
	char	**old_argv;
	char	**new_argv;

	if (!cmd || !cmd->argv)
		return ;
	old_argv = cmd->argv;
	new_argv = expand_argv(old_argv, shell);
	if (new_argv)
	{
		cmd->argv = new_argv;
		free_argv(old_argv);
	}
}
