/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:32:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/27 15:54:56 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_sh;

void	execute_string(char *input)
{
	t_list	*pipelines;

	pipelines = get_pipelines(input);
	execute_pipelines(pipelines);
	ft_lstclear(&pipelines, lst_del_command);
}

int	main(int ac, const char **av, t_environment envp)
{
	(void)ac;
	(void)av;
	g_sh = create_shell(av[0], envp);
	if (ac == 1)
		run_shell();
	else if (ac == 3 && !ft_strcmp("-c", av[1]))
		execute_string((char *)av[2]);
	else
		ft_printf("probleme args\n");	
	destroy_shell(g_sh);
	return (0);
}
