/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/26 02:39:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		export_error(const char *arg)
{
	ft_printf("%s: ", g_sh.name);
	ft_printf("export: ");
	ft_printf("`%s`: ", arg);
	ft_printf("not a valid identifier\n");
	return (0);
}

int		export(const char **args)
{
	int			i;
	char		*equal_pos;
	const char	*env_var;

	i = 0;
	while (args[++i])
	{
		if (!ft_isalpha(args[i][0]) && args[i][0] != '_')
			export_error(args[i]);
		if ((equal_pos = ft_strchr(args[i], '=')) != NULL)
		{
			*equal_pos = '\0';
			env_var = get_environment_variable((char *)args[i]);
			if (env_var == NULL)
			{
				*equal_pos = '=';
				add_environment_variable((char *)args[i]);
			}
			else
				set_environment_variable_value((char *)args[i], equal_pos + 1);
		}
	}
	return (0);
}
