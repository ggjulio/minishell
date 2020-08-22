/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 16:06:05 by juligonz         ###   ########.fr       */
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
	return (ft_strchr(get_environment_variable(name), '=') + 1);
}

void	set_environment_variable_value(char *name, char *value)
{
	(void)name;
	(void)value;
}
