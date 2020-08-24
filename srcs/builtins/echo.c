/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/23 14:01:06 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     echo(char **args)
{
    int opt;
    int i;

    i = -1;
    opt = 0;
    if (args[0] && ft_strcmp(args[0], "-n") == 0)
    {
        opt = 1;
        i++;
    }
    if (args[0] == NULL && opt == 0)
    {
        ft_printf("\n");
        return (0);
    }
    while (args[++i])
    {
        if ((opt == 0 && i > 0) || (opt == 1 && i > 1))
            ft_printf(" ");
        ft_printf("%s", args[i]);
    }
    if (opt == 0)
        ft_printf("\n");
    return (0);
}