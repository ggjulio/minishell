/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/29 17:24:03 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     is_builtin(char *command)
{
    const char *internal[] = {"cd", "exit", "export", "unset", 0};
    const char  *external[] = {"echo", "env", "pwd", 0};
    int         i;

    i = -1;
    while (internal[++i])
        if (ft_strcmp(internal[i], command) == 0)
            return (1);
    i = -1;
    while (external[++i])
        if (ft_strcmp(external[i], command) == 0)
            return (2);
    return (0);
}

int     check_pipeline(t_command *pipeline)
{
    int i;

	i = -1;

    if (!(is_builtin(pipeline->args[0])) && pipeline->bin_path == NULL)
        bad_command(pipeline->args[0]);
    if (pipeline->pipe != NULL)
		check_pipeline(pipeline->pipe);
    return (1);
}

int     check_commands(t_list *commands)
{
    t_list *tmp;

    tmp = commands;
    while (tmp)
    {
        if (!check_pipeline(tmp->content))
            ft_printf("bad input\n");
        tmp = tmp->next;
    }
    return (0);
}