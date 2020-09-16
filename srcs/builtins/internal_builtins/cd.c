/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/16 23:43:44 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		has_only_slashes(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i++] != '/')
			return (0);
	return (1);
}

static void		do_cd(char *path)
{
	char	*tmp;

	set_environment_variable_value("OLDPWD", g_sh.cwd);
	free(g_sh.cwd);
	g_sh.cwd = getcwd(NULL, 0);
	if (path != NULL && ((!ft_strncmp(path, "//", 2) && !has_only_slashes(path))
		|| !ft_strcmp(path, "//")))
	{
		ft_asprintf(&tmp, "/%s", g_sh.cwd);
		free(g_sh.cwd);
		g_sh.cwd = tmp;
	}
	set_environment_variable_value("PWD", g_sh.cwd);
}

static int		cd_no_args(const char **args, char *var)
{
	if (!get_environment_variable(var))
	{
		ft_dprintf(2, "%s: %s: %s not set\n", g_sh.name, args[0], var);
		return (STATUS_FAILURE);
	}
	if (chdir(get_environment_variable_value(var)) == -1)
	{
		if (get_environment_variable(var)
			&& get_environment_variable_value(var)[0] == '\0')
			return (STATUS_SUCCESS);
		error("cd", get_environment_variable_value(var));
		return (STATUS_FAILURE);
	}
	if (ft_strcmp(var, "OLDPWD") == 0)
		ft_printf("%s\n", get_environment_variable_value(var));
	return (STATUS_SUCCESS);
}

static int		too_many_arguments(const char **args)
{
	if (ft_array_len((char **)args) <= 2)
		return (STATUS_SUCCESS);
	ft_dprintf(STDERR_FILENO, "%s: cd: too many arguments\n", g_sh.name);
	return (STATUS_FAILURE);
}

int				cd(const char **args)
{
	if (too_many_arguments(args) == STATUS_FAILURE)
		return (STATUS_FAILURE);
	if (args[1] == NULL)
	{
		if (cd_no_args(args, "HOME") == STATUS_FAILURE)
			return (STATUS_FAILURE);
	}
	else if (args[1][0] == '\0')
		return (STATUS_SUCCESS);
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (cd_no_args(args, "OLDPWD") == STATUS_FAILURE)
			return (STATUS_FAILURE);
	}
	else if (chdir(args[1]) == -1)
	{
		error("cd", args[1]);
		return (STATUS_FAILURE);
	}
	do_cd((char *)args[1]);
	return (STATUS_SUCCESS);
}
