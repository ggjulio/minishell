/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/20 18:33:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		prompt_name(void)
{
	ft_dprintf(STDERR_FILENO, "%s%s:%s ", "\e[92m", g_sh.name, "\e[94m");
	ft_dprintf(STDERR_FILENO, "%s%s$%s ", g_sh.cwd, "\e[91m", "\e[0m");
}

void		run_shell_commands(char **commands)
{
	t_command	*to_exec;
	int			i;

	i = -1;
	while (commands[++i])
	{
		if ((to_exec = get_pipeline(commands[i])) != NULL)
		{
			spawn_pipeline(to_exec);
			free_command(to_exec);
		}
	}
}

void		run_shell(void)
{
	char	*input;
	char	**commands;
	char	show_prompt;

	input = NULL;
	show_prompt = 1;
	while (g_sh.running)
	{
		if (show_prompt && !(show_prompt = 0))
			prompt_name();
		if (get_next_line(STDIN_FILENO, &input) != 0)
		{
			commands = split_input(input);
			if (commands != NULL)
			{
				run_shell_commands(commands);
				ft_free_array(commands);
			}
			show_prompt = 1;
		}
		else if (ft_strlen(input) < 1)
			g_sh.running = 0;
		free(input);
	}
}
