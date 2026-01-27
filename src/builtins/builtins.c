/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/27 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"
#include "minishell.h"
#include <string.h>

static int	str_equal(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	return (ft_strncmp(s1, s2, ft_strlen(s1)) == 0);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (str_equal(cmd, "echo") || str_equal(cmd, "cd"))
		return (1);
	if (str_equal(cmd, "pwd") || str_equal(cmd, "export"))
		return (1);
	if (str_equal(cmd, "unset") || str_equal(cmd, "env"))
		return (1);
	if (str_equal(cmd, "exit"))
		return (1);
	return (0);
}

static int	exec_builtin_sub(char **argv, t_shell *shell)
{
	if (str_equal(argv[0], "export"))
		return (builtin_export(argv, shell));
	if (str_equal(argv[0], "unset"))
		return (builtin_unset(argv, shell));
	if (str_equal(argv[0], "env"))
		return (builtin_env(shell));
	if (str_equal(argv[0], "exit"))
		return (builtin_exit(argv, shell));
	return (1);
}

static int	exec_builtin_cmd(char **argv, t_shell *shell)
{
	if (str_equal(argv[0], "echo"))
		return (builtin_echo(argv));
	if (str_equal(argv[0], "cd"))
		return (builtin_cd(argv, shell));
	if (str_equal(argv[0], "pwd"))
		return (builtin_pwd());
	return (exec_builtin_sub(argv, shell));
}

int	exec_builtin(char **argv, t_shell *shell)
{
	if (!argv || !argv[0])
		return (1);
	return (exec_builtin_cmd(argv, shell));
}
