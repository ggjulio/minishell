/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:49:36 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/07 18:19:37 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	while (wait(&g_sh.status) > 0)
		;
	ft_printf("\n");
	if (g_sh.status != 2)
		prompt_name();
	g_sh.status = STATUS_CTRL_C;
}

void	sigquit_handler(int sig)
{
	(void)sig;
	wait(&g_sh.status);
	if (g_sh.status == 3)
	{
		g_sh.status = STATUS_CTRL_BACKSLASH;
		ft_dprintf(1, "Quit: 3\n");
	}
}

int		set_signal(void)
{
	int status;

	while (wait(&status) > 0)
		;
	g_sh.status = status % 255;
	if (g_sh.status == 145)
		g_sh.status = 130;
	return (0);
}
