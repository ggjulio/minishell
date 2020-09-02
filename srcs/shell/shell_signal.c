/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:49:36 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/02 16:02:38 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	wait(&g_sh.status);
	if (g_sh.status == 2)
	{
		g_sh.status = 130;
		ft_printf("\n");
	}
	else
	{
		g_sh.status = 1;
		ft_printf("\n");
		prompt_name();
	}
}

void	sigquit_handler(int sig)
{
	(void)sig;
	wait(&g_sh.status);
	if (g_sh.status == 3)
	{
		g_sh.status = 131;
		ft_dprintf(1, "Quit: 3\n");
	}	
}