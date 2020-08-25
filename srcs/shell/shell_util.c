/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/25 17:28:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_commands(t_list	*commands)
{
	t_list		*iterator;
	t_command	*to_exec;

	iterator = commands;
	while	(iterator)
	{
		to_exec = iterator->content;
		spawn_command(to_exec);
		iterator = iterator->next;
	}
}

void	run_shell(void)
{
	char	*input;
	t_list	*pipelines;

	input = NULL;
	while (42)
	{
		ft_printf("%s%s:%s ", "\e[92m", g_sh.name, "\e[94m");
		ft_printf("%s%s$%s ", g_sh.cwd, "\e[91m", "\e[0m");
		get_next_line(STDIN_FILENO, &input);
		pipelines = get_pipelines(input);
		free(input);
		execute_commands(pipelines);
		ft_lstclear(&pipelines, lst_del_command);

	}
}
