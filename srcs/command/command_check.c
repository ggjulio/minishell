/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/23 14:01:06 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     is_builtin(char *command)
{
    const char  *builtins[] = {"echo", "cd", "env", "export", "pwd", "unset", "exit", 0};
    int         i;

    i = -1;
    while (builtins[++i])
    {
        if (ft_strcmp(builtins[i], command) == 0)
            return (1);
    }
    return (0);
}


int check_pipeline(t_command *pipeline)
{
    int i;

	i = -1;

    if (is_builtin(pipeline->args[0]))
        return (1);
    if (pipeline->bin_path == NULL)
        return (0);
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