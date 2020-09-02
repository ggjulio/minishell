/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/02 02:24:37 by juligonz         ###   ########.fr       */
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
		if (!ft_strncmp(name, g_sh.env[i], ft_strlen(name))
	&& ft_strlen(name) == (size_t)(ft_strchr(g_sh.env[i], '=') - g_sh.env[i]))
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
	int		i;
	char	**g_env;
	char	*to_add;

	i = -1;
	g_env = (char **)g_sh.env;
	ft_asprintf(&to_add, "%s=%s", name, value);
	if (!get_environment_variable(name))
	{
		add_environment_variable(to_add);
		free(to_add);
	}
	else
		while (g_sh.env[++i])
			if (!ft_strncmp(name, g_sh.env[i], ft_strlen(name))
	&& ft_strlen(name) == (size_t)(ft_strchr(g_sh.env[i], '=') - g_sh.env[i]))
			{
				free(g_env[i]);
				g_env[i] = to_add;
				return ;
			}
}
