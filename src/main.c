/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:46:42 by shkondo           #+#    #+#             */
/*   Updated: 2026/02/11 05:27:50 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"
#include <stdio.h>

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
		shell->exit_status = execute(cmd, shell);
		dispose_command(cmd);
	}
	free_tokens(tokens);
}

static void	loop(t_shell *shell)
{
	char	*line;

	setup_signals_interactive();
	while (1)
	{
		g_signal_received = 0;
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
		if (shell->should_exit)
		{
			break ;
		}
	}
}

static void	init_shell(t_shell *shell, char **envp)
{
	shell->env_list = init_env_list(envp);
	shell->exit_status = 0;
	shell->should_exit = 0;
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
