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

int    export_error(const char *arg)
{
    ft_printf("%s: ", g_sh.name);
    ft_printf("export: ");
    ft_printf("`%s`: ", arg);
    ft_printf("not a valid identifier\n");
    return (0);
}

int     export(const char **args)
{
    if (!ft_isalpha(args[1][0]) && args[1][0] != '_')
        export_error(args[1]);
    if (ft_strchr(args[1], '=') != NULL)
        add_environment_variable((char *)args[1]);
    return (0);
}

