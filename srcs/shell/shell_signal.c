/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:49:36 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/20 18:30:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	while (wait(&g_sh.status) > 0)
		;
	ft_printf("\n");
	if (g_sh.status != SIGINT)
		prompt_name();
	g_sh.status = STATUS_CTRL_C;
}

void	sigquit_handler(int sig)
{
	(void)sig;
	wait(&g_sh.status);
	if (g_sh.status == STATUS_CTRL_BACKSLASH)
		ft_dprintf(2, "Quit: 3\n");
}

int		set_signal(void)
{
	int status;

	status = 0;
	while (wait(&status) > 0)
		;
	if (status == 13)
		return (0);
	if (g_sh.status != STATUS_CTRL_BACKSLASH)
		g_sh.status = status % 255;
	if (g_sh.status == 145)
		g_sh.status = STATUS_CTRL_C;
	return (0);
}
