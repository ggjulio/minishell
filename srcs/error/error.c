/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/10 20:51:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		error(char *cmd, const char *arg)
{
	ft_dprintf(STDERR_FILENO, "%s: ", g_sh.name);
	if (cmd[0] != '\0')
		ft_dprintf(STDERR_FILENO, "%s: ", cmd);
	if (arg[0] != '\0')
		ft_dprintf(STDERR_FILENO, "%s: ", arg);
	ft_dprintf(STDERR_FILENO, "%s\n", strerror(errno));
	g_sh.status = STATUS_CMD_NOT_FOUND;
}

void		bad_command(char *cmd)
{
	ft_dprintf(STDERR_FILENO, "%s: %s: command not found\n", g_sh.name, cmd);
	g_sh.status = STATUS_CMD_NOT_FOUND;
}

int			permission_error(char *command, int option)
{
	ft_dprintf(STDERR_FILENO, "%s: ", g_sh.name);
	ft_dprintf(STDERR_FILENO, "%s: ", command);
	if (option == 1)
		ft_dprintf(STDERR_FILENO, "is a directory\n");
	else if (option == 2)
		ft_dprintf(STDERR_FILENO, "Permission denied\n");
	g_sh.status = STATUS_NOT_EXECUTABLE;
	return (0);
}
