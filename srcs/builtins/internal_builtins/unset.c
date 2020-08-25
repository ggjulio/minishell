/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/24 17:43:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     unset(const char **args)
{
    const char  *val;
    char        *tmp;
    char        *to_unset;

    if (get_environment_variable((char *)args[1]) == NULL)
        return (0);
    val = get_environment_variable_value((char *)args[1]);
    tmp = ft_strdupcat((char *)args[1], "=");
    to_unset = ft_strdupcat(tmp, (char *)val);
    free(tmp);
    remove_environment_variable(to_unset);
    free(to_unset);
    return (0);
}