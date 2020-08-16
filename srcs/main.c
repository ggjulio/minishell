/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:32:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/16 16:58:17 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_application	g_app;

int	main(int ac, char **av, char **envp)
{
	g_app = create_application(envp);
	(void)ac;
	(void)av;
	printf("OKKKKkKKKeeeeeee\n");

	char **tmp;
    for(tmp = envp; *tmp != 0; tmp++)
    {
        char *thisEnv = *tmp;
        printf("%s\n", thisEnv);
    }

	return (0);
}

