/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/26 17:23:06 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_environment(void)
{
	size_t i;

	i = 0;
	if (g_sh.env == NULL)
	{
		ft_printf("\nEnvironment array is NULL\n");
		return ;
	}
	while (g_sh.env[i])
		ft_printf("%s\n", g_sh.env[i++]);
}

const char	*get_environment_variable(char *name)
{
	int	i;

	if (!ft_strcmp(name, "$"))
		return (NULL);
	if (*name == '$')
		name++;
	i = -1;
	while (g_sh.env[++i])
		if (!ft_strncmp(name, g_sh.env[i], ft_strlen(name)))
			return (g_sh.env[i]);
	return (NULL);
}

const char	*get_environment_variable_value(char *name)
{
	const char *variable;
	variable = get_environment_variable(name);
	if (!variable)
		return (NULL);
	return (ft_strchr(variable, '=') + 1);
}

void		set_environment_variable_value(char *name, char *value)
{
	int	i;
	char **g_env;

	i = -1;
	g_env = (char **)g_sh.env;
	while (g_sh.env[++i])
		if (!ft_strncmp(name, g_sh.env[i], ft_strlen(name)))
		{
			free(g_env[i]);
			ft_asprintf(&(g_env[i]), "%s=%s", name, value);
			return ;	
		}
}
