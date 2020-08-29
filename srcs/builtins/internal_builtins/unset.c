/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/29 20:12:05 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     unset(const char **args)
{
    char        *to_unset;
    int         ret;

    ret = 0;
    int i = -1;
    while (args[++i])
    {
        to_unset = NULL;
        if (get_environment_variable((char *)args[i]) != NULL)
        {
            if (ft_asprintf(&to_unset, "%s=%s", args[i],
            get_environment_variable_value((char *)args[i])) == -1)
                return (-1);
        remove_environment_variable(to_unset);
        free(to_unset);
        }
        else
            ret++;    
    }
    return (ret);
}