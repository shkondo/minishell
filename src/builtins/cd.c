/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
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
#include <stdlib.h>
#include <unistd.h>

static void	print_cd_error(char *path)
{
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putendl_fd(": No such file or directory", STDERR_FILENO);
}

static int	update_pwd(t_shell *shell)
{
	char	*cwd;
	char	*oldpwd;

	oldpwd = get_var_value("PWD", shell->env_list);
	if (oldpwd)
		set_var_value("OLDPWD", oldpwd, &shell->env_list);
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		set_var_value("PWD", cwd, &shell->env_list);
		free(cwd);
	}
	return (0);
}

static char	*get_cd_path(char **argv, t_shell *shell)
{
	char	*path;

	if (!argv[1])
	{
		path = get_var_value("HOME", shell->env_list);
		if (!path)
		{
			ft_putendl_fd("minishell: cd: HOME not set", STDERR_FILENO);
			return (NULL);
		}
		return (path);
	}
	return (argv[1]);
}

int	builtin_cd(char **argv, t_shell *shell)
{
	char	*path;

	path = get_cd_path(argv, shell);
	if (!path)
		return (1);
	if (chdir(path) == -1)
	{
		print_cd_error(path);
		return (1);
	}
	update_pwd(shell);
	return (0);
}
