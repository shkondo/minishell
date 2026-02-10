/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2026/01/12 00:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

/* variables.c */
char	*get_var_value(char *name, t_env *env_list);
int		set_var_value(char *name, char *value, t_env **env_list);
int		unset_var(char *name, t_env **env_list);
t_env	*init_env_list(char **envp);
void	free_env_list(t_env *env);

/* variables_utils.c */
t_env	*find_env(char *name, t_env *env_list);
t_env	*create_env_node(char *name, char *value);
char	**env_list_to_envp(t_env *env_list);
int		env_list_size(t_env *env_list);

#endif
