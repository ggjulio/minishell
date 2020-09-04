/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/04 22:01:27 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_name(void)
{
	ft_printf("%s%s:%s ", "\e[92m", g_sh.name, "\e[94m");
	ft_printf("%s%s$%s ", g_sh.cwd, "\e[91m", "\e[0m");
}

void	run_shell(void)
{
	char		*input;
	char		**commands;
	t_command	*to_exec;
	int			i;

	input = NULL;
	while (g_sh.running)
	{
		prompt_name();
		if (get_next_line(STDIN_FILENO, &input) != 0)
		{
			commands = split_input(input, ';');
			i = -1;
			while (commands[++i])
				if ((to_exec = get_pipeline(commands[i])) != NULL)
				{
					spawn_pipeline(to_exec);
					free_command(to_exec);
				}
			ft_free_array(commands);
		}
		else
		{
			g_sh.running = 0;
			ft_printf("exit\n");
		}
		free(input);
	}
}
