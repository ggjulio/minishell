/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:03:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/24 17:45:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin_ptr	get_builtin_ptr(char *command_name)
{
	if (!ft_strcmp("echo", command_name))
		return (echo);
	if (!ft_strcmp("cd", command_name))
		return (cd);
	if (!ft_strcmp("env", command_name))
		return (env);
	if (!ft_strcmp("pwd", command_name))
		return (pwd);
	if (!ft_strcmp("export", command_name))
		return (export);
	if (!ft_strcmp("unset", command_name))
		return (&unset);
	if (!ft_strcmp("exit", command_name))
		return (exit_builtin);
	return (NULL);
}