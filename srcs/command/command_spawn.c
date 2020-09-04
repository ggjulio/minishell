/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_spawn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:45:43 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/04 18:26:28 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		redirect_pipe_end(int old, int new)
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
	else if (ft_strchr(command->args[0], '/') && !is_executable(command))
		exit(EXIT_FAILURE);
	else if (!(execve(command->bin_path, command->args, (char **)g_sh.env)))
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	return (0);
}

int			fork_command(t_command *pipeline, int *pfd, int in)
{
	pid_t			pid;

	pipe(pfd);
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
	close(pfd[1]);
	return (0);
}

int			spawn_pipeline(t_command *pipeline)
{
	int				pfd[2];
	int				in;

	in = 0;
	while (pipeline)
	{
		if (pipeline->redirections)
			redirection_hub(pipeline, pipeline->redirections);
		else
		{
			fork_command(pipeline, pfd, in);
			in = pfd[0];
		}
		pipeline = pipeline->pipe;
	}
	while (wait(&g_sh.status) > 0)
		;
	return (0);
}
