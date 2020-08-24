/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/24 17:42:44 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    export_error(char *arg)
{
    ft_printf("%s: ", g_sh.name);
    ft_printf("export: ");
    ft_printf("`%s`: ", arg);
    ft_printf("not a valid identifier\n");
    return (0);
}

int     export(const char **args)
{
    (void)args;
    // if (!ft_isalpha(arg[0]) && arg[0] != '_')
    //     export_error(arg);
    // if (ft_strchr(arg, '=') != NULL)
    //     add_environment_variable(arg);
    return (0);
}

