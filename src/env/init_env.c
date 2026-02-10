/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/02/11 05:27:50 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_name(char *env_str)
{
	int		len;
	char	*name;

	len = 0;
	while (env_str[len] && env_str[len] != '=')
		len++;
	name = ft_substr(env_str, 0, len);
	return (name);
}

static char	*extract_value(char *env_str)
{
	int		i;
	char	*value;

	i = 0;
	while (env_str[i] && env_str[i] != '=')
		i++;
	if (env_str[i] == '=')
		i++;
	value = ft_strdup(&env_str[i]);
	return (value);
}

static void	add_env_node(t_env **list, t_env *node)
{
	t_env	*tmp;

	if (!*list)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

t_env	*init_env_list(char **envp)
{
	t_env	*list;
	t_env	*node;
	char	*name;
	char	*value;
	int		i;

	list = NULL;
	i = 0;
	while (envp && envp[i])
	{
		name = extract_name(envp[i]);
		value = extract_value(envp[i]);
		node = create_env_node(name, value);
		free(name);
		free(value);
		if (node)
			add_env_node(&list, node);
		i++;
	}
	return (list);
}

void	free_env_list(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->name);
		free(env->value);
		free(env);
		env = tmp;
	}
}
