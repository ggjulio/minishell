/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/09 16:57:53 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd_no_args(const char **args, char *var)
{
	if (!get_environment_variable(var))
	{
		ft_dprintf(2, "%s: %s: %s not set\n", g_sh.name, args[0], var);
		g_sh.status = STATUS_FAILURE;
		return (0);
	}
	if (chdir(get_environment_variable_value(var)) == -1)
	{
		if (get_environment_variable(var)
			&& get_environment_variable_value(var)[0] == '\0')
			return (0);
		error("cd", get_environment_variable_value(var));
		return (0);
	}
	if (ft_strcmp(var, "OLDPWD") == 0)
		ft_printf("%s\n", get_environment_variable_value(var));
	return (1);
}

int		cd(const char **args)
{
	errno = 0;
	if (args[1] == NULL)
	{
		if (!cd_no_args(args, "HOME"))
			return (STATUS_FAILURE);
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (!cd_no_args(args, "OLDPWD"))
			return (STATUS_FAILURE);
	}
	else if (chdir(args[1]) == -1)
	{
		error("cd", args[1]);
		return (STATUS_FAILURE);
	}
	set_environment_variable_value("OLDPWD", g_sh.cwd);
	getcwd(g_sh.cwd, sizeof(g_sh.cwd));
	set_environment_variable_value("PWD", g_sh.cwd);
	return (STATUS_SUCCESS);
}
