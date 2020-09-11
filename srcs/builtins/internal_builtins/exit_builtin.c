/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/11 04:08:45 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int		is_number(const char *s)
// {
// 	int i;

// 	if (*s != '-' && *s != '+' && !ft_isdigit(*s) && !ft_isspace(*s))
// 		return (0);
// 	i = 0;
// 	while (s[++i])
// 		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]))
// 			return (0);
// 	return (1);
// }

static int		is_number(const char *s)
{
	int i;

	if (*s != '-' && *s != '+' && !ft_isdigit(*s) && !ft_isspace(*s))
		return (0);
	i = 1;
	while (s[i] && ft_isspace(s[i]))
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

static int		get_status(char *str, const char **args)
{
	(void)args;
	if (is_number(str))
	{
		return (ft_atoi(str));
	}
	return (STATUS_FAILURE_BUILTIN);
}

int				exit_builtin(const char **args)
{
	g_sh.running = 0;
	if (ft_array_len((char **)args) < 2)
		return (STATUS_SUCCESS);
	if (!is_number(args[1]))
	{
		ft_dprintf(2, "%s: %s: %s: numeric argument required\n",
			g_sh.name, args[0], args[1]);
		return (STATUS_FAILURE_BUILTIN);
	}
	if (ft_array_len((char **)args) > 2)
	{
		g_sh.running = 1;
		ft_dprintf(2, "%s: %s: too many arguments\n", g_sh.name, args[0]);
		return (STATUS_FAILURE);
	}
	return (get_status((char *)args[1], args));
}
