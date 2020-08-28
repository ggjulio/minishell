/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/28 02:15:30 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_pipelines(t_list	*commands)
{
	t_list		*iterator;
	t_command	*to_exec;

	iterator = commands;
	while	(iterator)
	{
		to_exec = iterator->content;
		spawn_pipeline(to_exec);
		iterator = iterator->next;
	}
}

void	prompt_name()
{
	ft_printf("%s%s:%s ", "\e[92m", g_sh.name, "\e[94m");
	ft_printf("%s%s$%s ", g_sh.cwd, "\e[91m", "\e[0m");
}

void	sig_handler(int sig)
{
	int status;

	(void)sig;
	wait(&status);
	if (status != SIGINT)
	{
		ft_printf("\n");
		prompt_name();
	}
}




void	run_shell(void)
{
	char	*input;
	t_list	*pipelines;

	//g_sh.status = 1;
	g_sh.pid = 1;
	input = NULL;
	signal(SIGINT, sig_handler);
	//signal(SIGQUIT, sig_handler);
	while (g_sh.status)
	{
		prompt_name();
		get_next_line(STDIN_FILENO, &input);
		if (input[0] != '\0')
		{
			pipelines = get_pipelines(input);
			execute_pipelines(pipelines);
			ft_lstclear(&pipelines, lst_del_command);
		}
		else
		{
			free(input);
			exit_shell(EXIT_SUCCESS);
		}
		free(input);
	}
}
