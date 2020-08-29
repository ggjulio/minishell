/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/29 20:49:02 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_command(t_command *pipeline)
{
	int ret;

	ret = 1;
	if (pipeline->bin_path == NULL
		&& !get_builtin_ptr(pipeline->args[0])
		&& !get_internal_builtin_ptr(pipeline->args[0]))
	{
		bad_command(pipeline->args[0]);
		ret = 0;
	}
	if (pipeline->pipe != NULL)
		ret = is_valid_command(pipeline->pipe) ? ret : 0;
	return (ret);
}

int			is_valid_pipeline(t_command *pipeline)
{
	if (pipeline == NULL)
		ft_printf("empty pipeline in command check\n");
	return (is_valid_command(pipeline));
}
