/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:06:19 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/31 18:54:45 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(int status)
{
	ft_printf("exit\n");
	destroy_shell(g_sh);
	exit(status);
}

void	d_exit_shell()
{
	signal(SIGINT, NULL);
	ft_printf("exit");
	if (g_sh.status != 1 && g_sh.status != 130)
		ft_printf("\n");
	destroy_shell(g_sh);
	exit(EXIT_SUCCESS);
}