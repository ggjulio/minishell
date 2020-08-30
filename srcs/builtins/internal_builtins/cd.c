/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/30 23:24:33 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd(const char **args)
{
	errno = 0;
	if (args[1] == NULL)
	{
		if (chdir(get_environment_variable_value("HOME")) == -1)
		{
			error("cd", args[1]);
			return (-1);
		}
	}
	else if (chdir(args[1]) == -1)
	{
		error("cd", args[1]);
		return (-1);
	}
	set_environment_variable_value("OLDPWD", g_sh.cwd);
	getcwd(g_sh.cwd, sizeof(g_sh.cwd));
	set_environment_variable_value("PWD", g_sh.cwd);
	return (0);
}
