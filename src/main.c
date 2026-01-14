/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:46:42 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/14 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_line(char *line, t_shell *shell)
{
	t_token	*tokens;
	t_cmd	*cmd;

	tokens = tokenize(line);
	if (!tokens)
		return ;
	cmd = parse_pipeline(tokens);
	if (cmd)
	{
		/* TODO: execute(cmd, shell) */
		(void)shell;
		dispose_command(cmd);
	}
	free_tokens(tokens);
}

static void	loop(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		if (*line)
		{
			add_history(line);
			process_line(line, shell);
		}
		free(line);
	}
}

static void	init_shell(t_shell *shell, char **envp)
{
	shell->env_list = init_env_list(envp);
	shell->exit_status = 0;
	shell->envp = envp;
}

static void	cleanup_shell(t_shell *shell)
{
	free_env_list(shell->env_list);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	init_shell(&shell, envp);
	loop(&shell);
	cleanup_shell(&shell);
	return (shell.exit_status);
}
