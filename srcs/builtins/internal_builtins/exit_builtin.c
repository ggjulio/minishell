/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/13 17:53:11 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_valid(const char *s)
{
	int						i;
	int						sign;
	unsigned long int	res;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	while (ft_isdigit(s[i]))
		res = res * 10 + s[i++] - '0';
	if (sign == 1 && res > (unsigned long int)LONG_MAX)
		return (0);
	if (sign == -1 && res > (unsigned long int)LONG_MAX + 1)
		return (0);
	return (1);
}

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
	if (!is_valid(s))
		return (0);
	return (1);
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
	return (ft_atoi(args[1]));
}
