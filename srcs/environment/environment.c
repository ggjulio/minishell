/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:34:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/18 18:25:50 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_environment	create_environment(char **envp)
{
	t_environment result;

		
	return (result);
}

t_environment	*malloc_environment(char **envp)
{
	t_environment *result;

	if ((result = malloc(sizeof(t_environment))) == NULL)
		return (NULL);
	*result = create_environment(envp);
	return (result);
}

void	destroy_environment(t_environment to_destroy)
{
	(void)to_destroy;
}

void	free_environment(t_environment *to_free)
{
	destroy_environment(*to_free);
	free(to_free);
}

