/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:46:42 by shkondo           #+#    #+#             */
/*   Updated: 2025/12/24 21:36:45 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args) == -1)
			perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("Error");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

void	loop(void)
{
	char	*line;
	t_token	**args;
	t_token	**cmd_list;
	int		status;

	status = 1;
	while (1)
	{
		line = readline("msh$ ");
		if (!line)
		{
			free(line);
			break ;
		}
		if (*line)
			add_history(line);
		args = tokenize(line);
		cmd_list = parse(args);
		status = execute(cmd_list);
		free(line);
		ft_list_free(args);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	loop();
	return (0);
}
