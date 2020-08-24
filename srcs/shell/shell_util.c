/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/24 01:28:27 by juligonz         ###   ########.fr       */
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
		if (ft_strcmp(to_exec->args[0], "echo") == 0)
			echo(&to_exec->args[1]);
		else if (ft_strcmp(to_exec->args[0], "cd") == 0)
			cd(to_exec->args[1]);
		else if (ft_strcmp(to_exec->args[0], "env") == 0)
			env();
		else if (ft_strcmp(to_exec->args[0], "pwd") == 0)
			pwd();
		else if (ft_strcmp(to_exec->args[0], "export") == 0)
			export(to_exec->args[1]);
		else if (ft_strcmp(to_exec->args[0], "unset") == 0)
			unset(to_exec->args[1]);
		else if (ft_strcmp(to_exec->args[0], "exit") == 0)
			exit_builtin();	
		else
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
		ft_printf("%s%s:%s ", "\e[92m", g_sh.name, "\e[94m");
		ft_printf("%s%s$%s ", g_sh.cwd, "\e[91m", "\e[0m");
		get_next_line(STDIN_FILENO, &input);
		execute_commands(get_commands(input));
		free(input);
	}
}
