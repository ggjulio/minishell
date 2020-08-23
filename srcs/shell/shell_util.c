/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/23 23:49:43 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int spawn (char* bin_path, char** arg_list, char **envp)
{
	pid_t	child_pid;
	int		status;

	child_pid = fork ();
	if (child_pid == -1)
		return (-1);
	if (child_pid != 0)
	{
		waitpid(child_pid, &status, 0);
    	return child_pid;
	}
	else {
    	execve (bin_path, arg_list, envp);
    	ft_printf("une erreur est survenue au sein de execvp\n");
	}
	return (0);
}



void	execute_commands(t_list	*commands)
{
	t_list		*iterator;
	t_command	*to_exec;

	iterator = commands;
	while	(iterator)
	{
		to_exec = iterator->content;
		spawn (to_exec->bin_path, to_exec->args, (char **)g_sh.env);
		iterator = iterator->next;
	}
}



void	run_shell(void)
{
	char	*input;

	input = NULL;
	while (42)
	{
		ft_printf("%s%s%s$%s ", "\e[92m", g_sh.name, "\e[91m", "\e[0m");
		get_next_line(STDIN_FILENO, &input);
		execute_commands(get_commands(input));
		free(input);
	}
}
