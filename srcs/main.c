/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:32:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/17 18:11:41 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_application	g_app;

int	main(int ac, char **av, char **envp)
{
	g_app = create_application(av[0], envp);
	(void)ac;
	(void)av;
	ft_printf("OK\n");
	ft_printf("%s\n", g_app.name);

	// char **tmp;
    // for(tmp = envp; *tmp != 0; tmp++)
    // {
    //     char *thisEnv = *tmp;
    //     ft_printf("%s\n", thisEnv);
    // }

	destroy_application(g_app);
	return (0);
}

