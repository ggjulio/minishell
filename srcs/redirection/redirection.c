/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:04:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/31 16:18:16 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirection	create_redirection(char *p_filename, t_redirection_type p_type)
{
	t_redirection	result;

	result.str = ft_strdup(p_filename);
	result.type = p_type;
	return (result);
}

t_redirection	*malloc_redirection(char *p_filename, t_redirection_type p_type)
{
	t_redirection	*result;

	if ((result = malloc(sizeof(t_redirection))) == NULL)
		return (NULL);
	*result = create_redirection(p_filename, p_type);
	return (result);
}

void			destroy_redirection(t_redirection to_destroy)
{
	free(to_destroy.str);
}

void			free_redirection(t_redirection *to_free)
{
	destroy_redirection(*to_free);
	free(to_free);
}

void			lst_del_redirection(void *to_free)
{
	free_redirection(to_free);
}
