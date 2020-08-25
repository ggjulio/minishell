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


int			fork_execve(t_command *command)
{
	pid_t 			pid = 0;
	int				status;

	if ((pid = fork()) < 0)
		return (-1);
	if (pid != 0)
	{
		waitpid(pid, &status, 0);
    	return (pid);
	}
	else
		execve(command->bin_path, command->args, (char **)g_sh.env);
	return (0);
}


int			run_command(t_command *command)
{
	t_builtin_ptr	builtin;

	if ((builtin = get_internal_builtin_ptr(command->args[0])) != NULL)
 		(*builtin)((const char **)command->args);
	else if ((builtin = get_builtin_ptr(command->args[0])) != NULL)
		(*builtin)((const char **)command->args);
	else if (command->bin_path != NULL)
	{
		if (command->pipe == NULL)
			fork_execve(command);
		else 
    		execve(command->bin_path, command->args, (char **)g_sh.env);
	}	
	return (0);
}


int			spawn_piped_command(int in, int out, t_command *command)
{
	pid_t			pid;

	if ((pid = fork()) == -1)
		return (-1);
	if (pid != 0)
		return (pid);
	if (in != STDIN_FILENO)
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
	if (out != STDOUT_FILENO)
	{
		dup2(out, STDOUT_FILENO);
		close(out);
	}
	run_command(command);
	return (pid);
}

int			spawn_single_command(t_command *command)
{
	pid_t 			pid = 0;
	int				status;

	if ((pid = fork()) < 0)
		return (-1);
	if (pid != 0)
	{
		waitpid(pid, &status, 0);
    	return (pid);
	}
	else
		return (run_command(command));
	return (0);
}

int			spawn_command(t_command *command)
{
	int				pipe_fd[2];
	int				in;

	in = 0;
	if (command->pipe == NULL)
		return (spawn_single_command(command));
	while (command->pipe)
	{
		pipe(pipe_fd);
		spawn_piped_command(in, pipe_fd[1], command);
		close(pipe_fd[1]);
		in = pipe_fd[0];
		command = command->pipe;
	}
	return (run_command(command));
}