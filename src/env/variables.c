/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	str_equal(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	return (ft_strncmp(s1, s2, ft_strlen(s1)) == 0);
}

char	*get_var_value(char *name, t_env *env_list)
{
	t_env	*node;

	if (!name)
		return (NULL);
	node = find_env(name, env_list);
	if (node)
		return (node->value);
	return (NULL);
}

int	set_var_value(char *name, char *value, t_env **env_list)
{
	t_env	*node;
	t_env	*new_node;

	if (!name || !env_list)
		return (-1);
	node = find_env(name, *env_list);
	if (node)
	{
		free(node->value);
		node->value = ft_strdup(value);
		return (0);
	}
	new_node = create_env_node(name, value);
	if (!new_node)
		return (-1);
	new_node->next = *env_list;
	*env_list = new_node;
	return (0);
}

int	unset_var(char *name, t_env **env_list)
{
	t_env	*prev;
	t_env	*cur;

	if (!name || !env_list || !*env_list)
		return (-1);
	cur = *env_list;
	if (str_equal(cur->name, name))
	{
		*env_list = cur->next;
		free(cur->name);
		free(cur->value);
		free(cur);
		return (0);
	}
	prev = cur;
	cur = cur->next;
	while (cur)
	{
		if (str_equal(cur->name, name))
		{
			prev->next = cur->next;
			free(cur->name);
			free(cur->value);
			free(cur);
			return (0);
		}
		prev = cur;
		cur = cur->next;
	}
	return (-1);
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
