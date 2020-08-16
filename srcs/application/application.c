/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:52:21 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/16 17:00:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_application	create_application(char **envp)
{
	t_application result;

	(void)envp;
	ft_bzero(&result, sizeof(t_application));
	return (result);
}

t_application	*malloc_application(char **envp)
{
	t_application *result;

	if ((result = malloc(sizeof(t_application))) == NULL)
		return (NULL);
	*result = create_application(envp);
	return (result);
}

void			destroy_application(t_application to_destroy)
{
	(void)to_destroy;
}

void			free_application(t_application *to_free)
{
	destroy_application(*to_free);
	free(to_free);
}
