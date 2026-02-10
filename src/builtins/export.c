/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
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

static int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_export_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
}

static int	export_var(char *arg, t_shell *shell)
{
	char	*name;
	char	*value;
	char	*eq_pos;

	eq_pos = ft_strchr(arg, '=');
	if (eq_pos)
	{
		name = ft_substr(arg, 0, eq_pos - arg);
		value = ft_strdup(eq_pos + 1);
		if (!name || !value)
		{
			free(name);
			free(value);
			return (1);
		}
		set_var_value(name, value, &shell->env_list);
		free(name);
		free(value);
	}
	return (0);
}

int	builtin_export(char **argv, t_shell *shell)
{
	int	i;
	int	ret;

	ret = 0;
	if (!argv[1])
		return (builtin_env(shell));
	i = 1;
	while (argv[i])
	{
		if (!is_valid_identifier(argv[i]))
		{
			print_export_error(argv[i]);
			ret = 1;
		}
		else
			export_var(argv[i], shell);
		i++;
	}
	return (ret);
}
