/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/27 17:18:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_error(const char *arg)
{
	ft_printf("%s: ", g_sh.name);
	ft_printf("export: ");
	ft_printf("`%s`: ", arg);
	ft_printf("not a valid identifier\n");
	return (0);
}

static void	print_export_no_args()
{
	int		i;
	char	*equal_pos;
	char	*value_position;

	i = -1;
	while (g_sh.env[++i])
	{
		equal_pos = ft_strchr(g_sh.env[i], '=');
		*equal_pos = '\0';
		value_position = equal_pos + 1;
		ft_printf("declare -x %s=\"%s\"\n", g_sh.env[i], value_position);
		*equal_pos = '=';
	}
}

int			export(const char **args)
{
	int			i;
	char		*equal_pos;
	const char	*env_var;

	i = 0;
	if (ft_array_len((char **)args) > 1)
	{
		while (args[++i])
			if (!ft_isalpha(args[i][0]))
				export_error(args[i]);
			else if ((equal_pos = ft_strchr(args[i], '=')) != NULL)
			{
				*equal_pos = '\0';
				env_var = get_environment_variable((char *)args[i]);
				if (env_var == NULL && (*equal_pos = '='))
					add_environment_variable((char *)args[i]);
				else
					set_environment_variable_value((char *)args[i], equal_pos + 1);
				*equal_pos = '=';
			}
	}
	else
		print_export_no_args();
	return (0);
}
