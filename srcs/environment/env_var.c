/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:16:22 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 15:46:02 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_var	create_env_var(char *env_var)
{
	t_env_var	result;
	char		*equal_position;

	equal_position = ft_strchr(env_var, '=');
	result.name = ft_strndup(env_var, equal_position - env_var);
	result.value = ft_strdup(equal_position + 1);
	return (result);
}

t_env_var	*malloc_env_var(char *env_var)
{
	t_env_var *result;

	if ((result = malloc(sizeof(t_env_var))) == NULL)
		return (NULL);
	*result = create_env_var(env_var);
	return (result);
}

void		destroy_env_var(t_env_var to_destroy)
{
	free(to_destroy.name);
	free(to_destroy.value);
}

void		free_env_var(t_env_var *to_free)
{
	destroy_env_var(*to_free);
	free(to_free);
}

void		lst_del_env_elem(void *to_free)
{
	free_env_var(to_free);
}
