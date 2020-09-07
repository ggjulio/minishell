/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/07 13:32:18 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env(const char **args)
{
	int i;

	(void)args;
	i = -1;
	while (g_sh.env[++i])
		ft_printf("%s\n", g_sh.env[i]);
	exit(EXIT_SUCCESS);
	return (0);
}
