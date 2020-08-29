/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:45:43 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/29 16:49:59 by hwinston         ###   ########.fr       */
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




/*--------------------------------------------------------------*/




void 		redirect_pipe_end(int old, int new) 
{
	int ret;
	
	if (old != new)
	{
		ret = dup2(old, new);
		close(old);
		if (ret == -1)
			ft_printf("dup2 failed...\n");
	}
}

int			fork_execve(t_command *command)
{
	pid_t 			pid = 0;
	int				status;

	if ((pid = fork()) < 0)
		return (-1);
	if (pid != 0)
		waitpid(pid, &status, 0);
	else
		if (!(execve(command->bin_path, command->args, (char **)g_sh.env)))
			exit(EXIT_FAILURE);
	return (pid);
}

int			run_command(t_command *command)
{
	t_builtin_ptr	builtin;
	// int pid;
	// int status;

	// pid = fork();
	// if (pid > 0)
	// 	waitpid(pid, &status, 0);
	// else
	// {
	if ((builtin = get_internal_builtin_ptr(command->args[0])) != NULL)
 		(*builtin)((const char **)command->args);
	else if ((builtin = get_builtin_ptr(command->args[0])) != NULL)
		(*builtin)((const char **)command->args);

	else if (command->bin_path != NULL && command->pipe == NULL)
		fork_execve(command);
	else if ((command->bin_path != NULL))
		if (!(execve(command->bin_path, command->args, (char **)g_sh.env)))
			exit(EXIT_FAILURE);
	// }
	return (0);
}

int			spawn_piped_command(t_command *command, int in, int out)
{
	pid_t			pid;
	int				status;

	if ((pid = fork()) == -1)
		return (-1);
	if (pid > 0)
	{
		close(out);
		ft_dprintf(2, "----> PARENT OUT has been closed\n");
		waitpid(pid, &status, 0);
		return (pid);
	}

	ft_dprintf(2, "IN = %d | OUT = %d\n", in, out);
	
	if (in != 0)
	{
		redirect_pipe_end(in, STDIN_FILENO);
		ft_dprintf(2, "IN has been closed\n");
	}
	if (out != 1)
	{
		redirect_pipe_end(out, STDOUT_FILENO);
		ft_dprintf(2, "OUT has been closed\n");
	}
	
	run_command(command);
	close (in);
	
	exit(EXIT_SUCCESS);
	return (pid);
}
/*
int			spawn_pipeline(t_command *pipeline)
{
	int				pipe_fd[2];
	int				in;

	char *input;

	in = 0;
	if (pipeline->pipe == NULL)
		return (run_command(pipeline));
	while (pipeline->pipe)
	{
		pipe(pipe_fd);
		spawn_piped_command(pipeline, in, pipe_fd[1]);
		in = pipe_fd[0];
		//close(pipe_fd[0]);

	
		get_next_line(in, &input);
		ft_dprintf(2, "IN (%d) = %s\nstdin = %d\n", in, input, STDIN_FILENO);
		ft_dprintf(2, "-----------\n");

		pipeline = pipeline->pipe;
	}
	// if (in != STDIN_FILENO)
	// 	redirect_pipe_end(in, STDIN_FILENO);

	//dup2(STDIN_FILENO, in);

	ft_dprintf(2,"--- LAST ---\n");
	get_next_line(in, &input);
	ft_dprintf(2, "IN (%d) = %s\nstdin = %d\n", in, input, STDIN_FILENO);
	ft_dprintf(2, "-----------\n");

	run_command(pipeline);
	//dup2(0, STDIN_FILENO);

	//  close(pipe_fd[1]);
	close(pipe_fd[0]);
	// dup2(0, STDIN_FILENO);
	ft_dprintf(2, "----> PARENT IN has been closed\n");
	return(0);
}

*/


// int sjf(t_command *command)
// {
// 	return (0);
// }





int spawn_pipeline(t_command *command)
{
	pid_t		pid;
	int			status;
	int			pfd[2];
	int			in;
	t_builtin_ptr	builtin;

	in = 0;
	while (command)
    {
		if (!command->pipe && ft_strcmp(command->args[0], "exit") == 0)
			exit_builtin((const char **)command->args);
    	pipe(pfd);
      	if ((pid = fork()) == -1)
        	exit(EXIT_FAILURE);
    	else if (pid == 0)
    	{
        	dup2(in, 0);
        	if (command->pipe)
        		dup2(pfd[1], STDOUT_FILENO);
        	close(pfd[0]);
			if ((builtin = get_internal_builtin_ptr(command->args[0])) != NULL)
 				(*builtin)((const char **)command->args);
			else if ((builtin = get_builtin_ptr(command->args[0])) != NULL)
				(*builtin)((const char **)command->args);
			else if (!(execve(command->bin_path, command->args, (char **)g_sh.env)))
			exit(EXIT_FAILURE);
			//run_command(command);
        }
		waitpid(pid, &status, 0);
		close(pfd[1]);
		in = pfd[0];
		command = command->pipe;
    }
	return (0);
}