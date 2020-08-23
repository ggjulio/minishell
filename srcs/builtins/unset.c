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

int     unset(char *name)
{
    const char  *val;
    char        *tmp;
    char        *to_unset;

    if (get_environment_variable(name) == NULL)
        return (0);
    val = get_environment_variable_value(name);
    tmp = ft_strdupcat(name, "=");
    to_unset = ft_strdupcat(tmp, (char *)val);
    free(tmp);
    remove_environment_variable(to_unset);
    free(to_unset);
    return (0);
}