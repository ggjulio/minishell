/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/06 11:11:28 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_number(const char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if ((i == 0 && s[i] != '-' && !ft_isdigit((int)s[i]))
		|| (i > 0 && !ft_isdigit((int)s[i])))
			return (0);
	return (1);
}

static int		exit_error(const char **args)
{
	int ret;

	ret = 0;
	if (ft_strcmp(args[1], "--") == 0 && !args[2])
		return (ret);
	if (is_number(args[1]) && args[2])
	{
		ft_dprintf(2, "%s: %s: too many arguments\n", g_sh.name, args[0]);
		return (-1);
	}
	else if (is_number(args[1]) && ft_strcmp(args[1], "-") != 0)
		ret = ft_atoi(args[1]);
	else
	{
		ret = 255;
		ft_dprintf(2, "%s: %s: %s: numeric argument required\n",
		g_sh.name, args[0], args[1]);
	}
	return (ret);
}

int				exit_builtin(const char **args)
{
	int		ret;

	ret = 0;
	ft_printf("exit\n");
	if (args[1])
	{
		if ((ret = exit_error(args)) == -1)
		{
			g_sh.status = STATUS_FAILURE;
			return (ret);
		}
	}
	g_sh.status = STATUS_SUCCESS;
	g_sh.running = 0;
	return (ret);
}
