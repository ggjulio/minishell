/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:52:21 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/15 18:02:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_application	create_application(void)
{
	t_application result;

	ft_bzero(&result, sizeof(t_application));
	return (result);
}

t_application	*malloc_application(void)
{
	t_application *result;

	if ((result = malloc(sizeof(t_application))) == NULL)
		return (NULL);
	*result = create_application();
	return(result);
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
