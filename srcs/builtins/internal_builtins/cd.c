/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/24 18:41:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     cd(const char **args)
{
    (void)args;
    if (args[1] == NULL)
        return (0);
    errno = 0;
    if (chdir(args[1]) == -1)
    {
        error("cd", args[1]);
        return (-1);
    }
    getcwd(g_sh.cwd, sizeof(g_sh.cwd));
    return (0);
}