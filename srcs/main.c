/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:32:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/20 18:48:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_sh;

int			main(int ac, const char **av, t_environment envp)
{
	g_sh = create_shell(av[0], envp);
	set_environment_variable_value("PWD", g_sh.cwd);
	if (ac == 1)
	{
		run_shell();
		ft_dprintf(STDERR_FILENO, "exit\n");
	}
	else
		ft_dprintf(STDERR_FILENO,
			"minishell: Invalid arguments.\nUsage :  ./minishell\n");
	destroy_shell(g_sh);
	return (g_sh.status);
}
