/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/09 03:16:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		echo(const char **args)
{
	int no_nl;
	int i;

	if (args[1] == NULL)
	{
		ft_printf("\n");
		exit(EXIT_SUCCESS);
		return (0);
	}
	no_nl = 1;
	while (args[no_nl] && !ft_strcmp(args[no_nl], "-n"))
		no_nl++;
	i = no_nl - 1;
	while (args[++i])
	{
		ft_printf("%s", args[i]);
		if (args[i + 1])
			ft_printf(" ");
	}
	if (no_nl <= 1)
		ft_printf("\n");
	exit(EXIT_SUCCESS);
	return (0);
}
