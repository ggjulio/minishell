/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/06 02:04:06 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_command_not_found(t_command *pipeline)
{
	while (pipeline)
	{
		if (pipeline->bin_path == NULL
		&& !get_builtin_ptr(pipeline->args[0])
		&& !get_internal_builtin_ptr(pipeline->args[0])
		&& (pipeline->args[0] != NULL))
			bad_command(pipeline->args[0]);
		pipeline = pipeline->pipe;
	}
}
