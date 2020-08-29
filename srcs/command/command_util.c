/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:45:43 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/29 17:32:32 by hwinston         ###   ########.fr       */
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
	int		i;

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

void 		redirect_pipe_end(int old, int new) 
{
	if (old != new)
	{
		dup2(old, new);
		close(old);
	}
}

int			run_command(t_command *command)
{
	t_builtin_ptr	builtin;

	if ((builtin = get_internal_builtin_ptr(command->args[0])) != NULL)
 		(*builtin)((const char **)command->args);
	else if ((builtin = get_builtin_ptr(command->args[0])) != NULL)
		(*builtin)((const char **)command->args);
	else if (!(execve(command->bin_path, command->args, (char **)g_sh.env)))
			exit(EXIT_FAILURE);
	return (0);
}

int			fork_command(t_command *pipeline, int *pfd, int in)
{
	pid_t			pid;
	int				status;

	if ((pid = fork()) == -1)
        exit(EXIT_FAILURE);
    else if (pid == 0)
    {
		redirect_pipe_end(in, STDIN_FILENO);
    	if (pipeline->pipe)
		redirect_pipe_end(pfd[1], STDOUT_FILENO);
    	close(pfd[0]);		
		run_command(pipeline);
    }
	waitpid(pid, &status, 0);
	close(pfd[1]);
	return (0);
}

int spawn_pipeline(t_command *pipeline)
{
	t_builtin_ptr	builtin;
	int				pfd[2];
	int				in;

	in = 0;
	while (pipeline)
    {
		if ((builtin = get_internal_builtin_ptr(pipeline->args[0])) != NULL)
		{	
			if (!pipeline->pipe)
				(*builtin)((const char **)pipeline->args);
			pipeline = pipeline->pipe;
		}
		else
		{
			pipe(pfd);
			fork_command(pipeline, pfd, in);
			in = pfd[0];
			pipeline = pipeline->pipe;
		}
    }
	return (0);
}