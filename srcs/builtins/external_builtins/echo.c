/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/24 17:33:18 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     echo(const char **args)
{
    int opt;
    int i;

    opt = (args[1] && ft_strcmp(args[1], "-n") == 0) ? 1 : 0;
    if (args[1] == NULL && opt == 0)
    {
        ft_printf("\n");
        return (0);
    }
    i = 0 + opt;
    while (args[++i])
    {
        if ((opt == 0 && i > 1) || (opt == 1 && i > 2))
            ft_printf(" ");
        ft_printf("%s", args[i]);
    }
    if (opt == 0)
        ft_printf("\n");
    return (0);
}