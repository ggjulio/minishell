/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:34:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 02:27:06 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_environment	malloc_environment(char **envp)
{
	t_environment	result;
	size_t			i;

	if (!(result = malloc(environment_len(envp) + 1)))
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
		free(to_free[i]);
		to_free[i++] = NULL;
	}
	free(to_free);
}

size_t			environment_len(char **envp)
{
	size_t	len;

	len = 0;
	while (envp[len])
		len++;
	return (len);
}