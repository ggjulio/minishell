/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 22:47:21 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/13 12:42:42 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		exec_internal_builtin(t_builtin_ptr to_exec, char **args)
{
	if (to_exec != exit_builtin)
		redirect_parent_to_null_on();
	if (to_exec == exit_builtin)
		g_sh.status = (*to_exec)((const char **)args);
	else
		(*to_exec)((const char **)args);
	if (to_exec != exit_builtin)
		redirect_parent_to_null_off();
}

int				run_internal_builtins(t_command *pipeline)
{
	t_builtin_ptr	builtin;
	t_command		*first;

	first = pipeline;
	while (pipeline)
	{
		if ((builtin = get_internal_builtin_ptr(pipeline->args[0])) != NULL)
			if (!pipeline->pipe && first == pipeline)
				exec_internal_builtin(builtin, pipeline->args);
		pipeline = pipeline->pipe;
	}
	return (0);
}
