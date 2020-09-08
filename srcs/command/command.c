/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/08 15:31:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	create_command(t_list *p_args, t_list *p_redirections)
{
	t_command	result;

	ft_bzero(&result, sizeof(t_command));
	result.args = lst_string_to_string_array(p_args);
	result.bin_path = get_exec_path(result.args[0]);
	result.pipe = NULL;
	result.redirections = p_redirections;
	return (result);
}

t_command	*malloc_command(t_list *p_args, t_list *p_redirections)
{
	t_command	*result;

	if ((result = malloc(sizeof(t_command))) == NULL)
		return (NULL);
	*result = create_command(p_args, p_redirections);
	return (result);
}

void		destroy_command(t_command to_destroy)
{
	if (to_destroy.pipe != NULL)
		free_command(to_destroy.pipe);
	free(to_destroy.bin_path);
	ft_free_array(to_destroy.args);
	ft_lstclear(&to_destroy.redirections, lst_del_redirection);
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
