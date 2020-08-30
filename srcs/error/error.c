/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/30 18:41:47 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void        error(char *cmd, const char *arg)
{
    ft_dprintf(STDERR_FILENO, "%s: ", g_sh.name);
    ft_dprintf(STDERR_FILENO, "%s: ", cmd);
    ft_dprintf(STDERR_FILENO, "%s: ", arg);
    ft_dprintf(STDERR_FILENO, "%s\n", strerror(errno));
}

void        bad_command(char *cmd)
{
    ft_printf("%s: %s: command not found\n", g_sh.name, cmd);
    g_sh.status = 127;
}

int         permission_error(char *command, int option)
{
    ft_dprintf(STDERR_FILENO, "%s: ", g_sh.name);
    ft_dprintf(STDERR_FILENO, "%s: ", command);
    if (option == 1)
        ft_dprintf(STDERR_FILENO, "is a directory\n");
    else if (option == 2)
        ft_dprintf(STDERR_FILENO, "Permission denied\n");
    g_sh.status = 126;
    return (0);
}