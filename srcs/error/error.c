/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/23 14:01:06 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void     error(char *cmd, const char *arg)
{
    ft_dprintf(STDERR_FILENO, "%s: ", g_sh.name);
    ft_dprintf(STDERR_FILENO, "%s: ", cmd);
    ft_dprintf(STDERR_FILENO, "%s: ", arg);
    ft_dprintf(STDERR_FILENO, "%s\n", strerror(errno));
}