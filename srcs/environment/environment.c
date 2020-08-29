/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:34:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/29 16:19:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_environment	malloc_environment(t_environment envp)
{
	t_environment	result;
	size_t			i;

	if (!(result = malloc((environment_len(envp) + 1) * sizeof(char *))))
		return (NULL);
	i = -1;
	while (envp[++i])
		result[i] = ft_strdup(envp[i]);
	result[i] = NULL;
	return (result);
}

void			free_environment(t_environment to_free)
{
	ft_free_array((char **)to_free);
}

void			add_environment_variable(char *variable)
{
	t_environment	new_env;
	int				i;

	if (!(new_env = malloc((environment_len(g_sh.env) + 2) * sizeof(char *))))
		return ;
	i = -1;
	while (g_sh.env[++i])
		new_env[i] = g_sh.env[i];
	new_env[i++] = ft_strdup(variable);
	new_env[i] = NULL;
	free(g_sh.env);
	g_sh.env = new_env;
}

void			remove_environment_variable(char *name)
{
	t_environment	new_env;
	int				i;
	int				j;

	if (!(new_env = malloc(environment_len(g_sh.env) * sizeof(char *))))
		return ;
	i = -1;
	j = 0;
	while (g_sh.env[++i])
	{
		if (ft_strcmp(g_sh.env[i], name) != 0)
			new_env[j++] = g_sh.env[i];
	}
	new_env[j] = NULL;
	free(g_sh.env);
	g_sh.env = new_env;
}

size_t			environment_len(t_environment envp)
{
	return (ft_array_len((char **)envp));
}
