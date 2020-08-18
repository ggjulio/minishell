/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:32:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/18 14:52:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_sh;
/*
**	char **tmp;
**    for(tmp = envp; *tmp != 0; tmp++)
**    {
**        char *thisEnv = *tmp;
**        ft_printf("%s\n", thisEnv);
**    }
*/

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	g_sh = create_shell(av[0], envp);
	run_shell();
	destroy_shell(g_sh);
	return (0);
}
