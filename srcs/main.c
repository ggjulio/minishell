/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:32:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 14:32:26 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_sh;

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	g_sh = create_shell(av[0], envp);
	// run_shell();
	destroy_shell(g_sh);
	g_sh.env.lst_env_var = NULL;
	//	system("leaks minishell");
	return (0);
}
