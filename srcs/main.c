/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:32:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/20 00:15:57 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_sh;

static void	execute_string(char *input)
{
	char	**commands;

	commands = split_input(input);
	if (commands != NULL)
	{
		run_shell_commands(commands);
		ft_free_array(commands);
	}
}

int			main(int ac, const char **av, t_environment envp)
{
	g_sh = create_shell(av[0], envp);
	set_environment_variable_value("PWD", g_sh.cwd);
	if (ac == 1)
	{
		run_shell();
		ft_dprintf(STDERR_FILENO, "exit\n");
	}
	else if (ac == 3 && !ft_strcmp("-c", av[1]))
		execute_string((char *)av[2]);
	else
		ft_dprintf(STDERR_FILENO,
			"minishell: Invalid arguments.\nUsage :  ./minishell\n");
	destroy_shell(g_sh);
	return (g_sh.status);
}
