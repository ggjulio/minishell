/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/29 20:56:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	create_command(t_list *p_args)
{
	t_command	result;

	ft_bzero(&result, sizeof(t_command));
	result.args = lst_token_to_string_array(p_args);
	result.bin_path = get_exec_path(result.args[0]);
	result.pipe = NULL;
	return (result);
}

t_command	*malloc_command(t_list *p_args)
{
	t_command	*result;

	if ((result = malloc(sizeof(t_command))) == NULL)
		return (NULL);
	*result = create_command(p_args);
	return (result);
}

void		destroy_command(t_command to_destroy)
{
	int i;

	if (to_destroy.pipe != NULL)
		free_command(to_destroy.pipe);
	free(to_destroy.bin_path);
	i = 0;
	ft_free_array(to_destroy.args);
}

void		free_command(t_command *to_free)
{
	destroy_command(*to_free);
	free(to_free);
}

void		lst_del_command(void *to_free)
{
	free_command(to_free);
}
