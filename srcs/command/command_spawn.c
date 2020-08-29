/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_spawn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:45:43 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/29 19:23:52 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		exit(EXIT_FAILURE);
    }
	waitpid(pid, &status, 0);
	close(pfd[1]);
	return (0);
}

int			spawn_pipeline(t_command *pipeline)
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