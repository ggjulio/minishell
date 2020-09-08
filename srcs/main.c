/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:32:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/08 17:12:48 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_sh;

static void	execute_string(char *input)
{
	char	**commands;

	commands = split_input(input);
	run_shell_commands(commands);
	ft_free_array(commands);
}

int			main(int ac, const char **av, t_environment envp)
{
	(void)ac;
	(void)av;
	g_sh = create_shell(av[0], envp);
	if (ac == 1)
		run_shell();
	else if (ac == 3 && !ft_strcmp("-c", av[1]))
		execute_string((char *)av[2]);
	else
		ft_printf("Bad args\n");
	destroy_shell(g_sh);
	return (g_sh.status);
}
