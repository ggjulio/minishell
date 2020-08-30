/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/30 23:47:56 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_name(void)
{
	ft_printf("%s%s:%s ", "\e[92m", g_sh.name, "\e[94m");
	ft_printf("%s%s$%s ", g_sh.cwd, "\e[91m", "\e[0m");
}

void	sigint_handler(int sig)
{
	(void)sig;
	wait(&g_sh.status);
	if (g_sh.status == 2)
	{
		g_sh.status = 130;
		ft_printf("\n");
	}
	else
	{
		g_sh.status = 1;
		ft_printf("\n");
		prompt_name();
	}
}

void	sigquit_handler(int sig)
{
	(void)sig;
	wait(&g_sh.status);
	if (g_sh.status == 3)
	{
		g_sh.status = 131;
		ft_dprintf(1, "Quit: 3\n");
	}	
}

void	run_shell(void)
{
	char		*input;
	char		**commands;
	t_command	*to_exec;
	int			i;

	input = NULL;
	while (42)
	{
		prompt_name();
		if (get_next_line(STDIN_FILENO, &input) == 0)
			exit_shell(EXIT_SUCCESS);
		commands = ft_split(input, ';');
		i = -1;
		while (commands[++i])
		{
			if ((to_exec = get_pipeline(commands[i])) != NULL)
			{
				spawn_pipeline(to_exec);
				free_command(to_exec);
			}
		}
		ft_free_array(commands);
		free(input);
	}
}
