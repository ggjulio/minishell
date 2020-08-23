/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:34:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 15:37:33 by juligonz         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (to_free[i])
	{
		free((char *)to_free[i]);
		to_free[i++] = NULL;
	}
	free(to_free);
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
	if (*variable == '$')
		variable++;
	new_env[i++] = ft_strdup(variable);
	new_env[i] = NULL;
	free(g_sh.env);
	g_sh.env = new_env;
}

void			remove_environment_variable(char *name)
{
	(void)name;
}

size_t			environment_len(t_environment envp)
{
	size_t	len;

	len = 0;
	while (envp[len])
		len++;
	return (len);
}
