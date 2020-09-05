/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/05 16:12:52 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_command(t_command *pipeline)
{
	int ret;

	ret = 1;
	if (pipeline->bin_path == NULL
		&& !get_builtin_ptr(pipeline->args[0])
		&& !get_internal_builtin_ptr(pipeline->args[0])
		&& (pipeline->args[0] != NULL))
	{
		bad_command(pipeline->args[0]);
		ft_printf("ok");
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
