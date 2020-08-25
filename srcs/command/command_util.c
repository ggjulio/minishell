/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:45:43 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/24 18:40:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_exec_path(char *exec_name)
{
	size_t			i;
	char			**paths;
    DIR				*dir;
    struct dirent	*dp;

	if (!ft_strncmp("./",exec_name, 2) || !ft_strncmp("/",exec_name, 1))
		return (ft_strdup(exec_name));
	paths = malloc_environment_path();
	i = -1;
	while (paths[++i])
	{
		dir = opendir(paths[i]);
		if (dir == NULL)
			continue;
		while ((dp = readdir(dir)) != NULL)
			if (!ft_strcmp(exec_name, dp->d_name))
			{
				char *tmp = ft_strdupcat(paths[i], "/");
				char *result = ft_strdupcat(tmp, exec_name);
				free(tmp);
				closedir(dir);
				free_environment_path(paths);
				return (result);
			}
		closedir(dir);
	}	
	free_environment_path(paths);
	return (NULL);
}

void		print_command(t_command *to_print)
{
	int i;

	i = 0;
	while (to_print->args[i])
		ft_printf("%s ", to_print->args[i++]);		
	if (to_print->pipe != NULL)
	{
		ft_printf(" | ");
		print_command(to_print->pipe);
		
	}
	ft_printf("\n");
}

// int spawn_command(t_command *command)
// {
// 	pid_t			child_pid;
// 	int				status;
// 	t_builtin_ptr	builtin;

// 	if ((builtin = get_internal_builtin_ptr(command->args[0])) != NULL)
// 		return ((*builtin)((const char **)command->args));
// 	child_pid = fork();
// 	builtin = get_builtin_ptr(command->args[0]);
// 	if (child_pid == -1)
// 		return (-1);
// 	if (child_pid != 0)
// 	{
// 		waitpid(child_pid, &status, 0);
//     	return child_pid;
// 	}
// 	else {
// 		if (builtin != NULL)
// 			(*builtin)((const char **)command->args);
// 		else if (command->bin_path != NULL)
//     		execve (command->bin_path, command->args, (char **)g_sh.env);
// 	}
// 	return (0);
// }

int fork_spawn(int in, int out, t_command *command)
{
	pid_t			pid;
	t_builtin_ptr	builtin;

	if ((pid = fork()) == -1)
		return (-1);
	if (pid != 0)
		return (0);
	if (in != 0)
	{
		dup2(in, 0);
		close(in);
	}
	if (out != 1)
	{
		dup2(out, 1);
		close(out);
	}
	builtin = get_builtin_ptr(command->args[0]);
	if (builtin != NULL)
		(*builtin)((const char **)command->args);
	else if (command->bin_path != NULL)
    	execve (command->bin_path, command->args, (char **)g_sh.env);
	return (pid);
}

int spawn_command(t_command *command)
{
	//pid_t			pid;
	//int				status;
	int				pipe_fd[2];
	t_builtin_ptr	builtin;
	int in;

	in = 0;
	while (command->pipe)
	{
		pipe(pipe_fd);
		fork_spawn(in, pipe_fd[1], command);
		close(pipe_fd[1]);
		in = pipe_fd[0];
		command = command->pipe;
	}
	if (in != 0)
		dup2(in, 0);
	builtin = get_builtin_ptr(command->args[0]);
	if (builtin != NULL)
		(*builtin)((const char **)command->args);
	else if (command->bin_path != NULL)
    	execve (command->bin_path, command->args, (char **)g_sh.env);
	return (0);
}