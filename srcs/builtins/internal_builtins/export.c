/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/11 18:16:56 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_error(const char *arg)
{
	ft_printf("%s: ", g_sh.name);
	ft_printf("export: ");
	ft_printf("`%s': ", arg);
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

static int	is_valid_identifier(const char *arg)
{
	int i;

	if (arg[0] == '\0' || ft_isdigit(arg[0]) || arg[0] == '=')
		return (0);
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (ft_in_charset(arg[i], NOT_VALID_CHARS_IN_VAR))
			return (0);
		i++;
	}
	return (1);
}

int			export(const char **args)
{
	int			i;
	char		*equal_pos;
	int			ret;

	i = 0;
	ret = STATUS_SUCCESS;
	if (ft_array_len((char **)args) > 1)
	{
		while (args[++i])
			if (!is_valid_identifier(args[i]))
			{
				export_error(args[i]);
				ret = STATUS_FAILURE;
			}
			else if ((equal_pos = ft_strchr(args[i], '=')) != NULL)
			{
				*equal_pos = '\0';
				set_environment_variable_value((char *)args[i], equal_pos + 1);
				*equal_pos = '=';
			}
	}
	else
		print_export_no_args();
	return (ret);
}
