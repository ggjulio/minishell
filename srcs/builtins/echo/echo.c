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
    if (ft_strcmp(args[0], "-n") == 0)
    {
        opt = 1;
        i++;
    }
    while (args[++i])
    {
        if ((opt == 0 && i%2 == 1) || (opt == 1 && i%2 == 0))
            ft_printf(" ");
        ft_printf("%s", args[i]);
    }
    if (opt == 0)
        ft_printf("\n");
    return (0);
}