/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/23 23:26:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	create_command(char **args)
{
	t_command	result;

	ft_bzero(&result, sizeof(t_command));
	result.bin_path = get_exec_path(args[0]);
	result.args = args;
	result.pipe = NULL;
	return (result);
}

t_command	*malloc_command(char **args)
{
	t_command	*result;

	if ((result = malloc(sizeof(t_command))) == NULL)
		return (NULL);
	*result = create_command(args);
	return (result);
}

void		destroy_command(t_command to_destroy)
{
	free(to_destroy.bin_path);
	(void)to_destroy;
}

void		free_command(t_command *to_free)
{
	destroy_command(*to_free);
	free(to_free);
}
