/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/05 19:15:15 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_error(const char *arg)
{
	ft_printf("%s: ", g_sh.name);
	ft_printf("export: ");
	ft_printf("`%s`: ", arg);
	ft_printf("not a valid identifier\n");
}

static void	print_export_no_args(void)
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

	i = 0;
	if (ft_array_len((char **)args) > 1)
	{
		while (args[++i])
			if (!ft_isalpha(args[i][0]))
				export_error(args[i]);
			else if ((equal_pos = ft_strchr(args[i], '=')) != NULL)
			{
				*equal_pos = '\0';
				set_environment_variable_value((char *)args[i], equal_pos + 1);
				*equal_pos = '=';
			}
	}
	else
		print_export_no_args();
	return (STATUS_SUCCESS);
}
