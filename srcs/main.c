/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:32:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/18 13:28:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_sh;

int	main(int ac, char **av, char **envp)
{
	g_sh = create_shell(av[0], envp);
	(void)ac;
	(void)av;
	ft_printf("OK\n");
	ft_printf("%s\n", g_sh.name);

	// char **tmp;
    // for(tmp = envp; *tmp != 0; tmp++)
    // {
    //     char *thisEnv = *tmp;
    //     ft_printf("%s\n", thisEnv);
    // }

	destroy_shell(g_sh);
	return (0);
}

