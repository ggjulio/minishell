/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_spawn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:45:43 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/06 20:50:25 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			redirect_pipe_end(int old, int new)
{
	if (old != new)
	{
		dup2(old, new);
		close(old);
	}
}

int				run_command(t_command *command)
{
	t_builtin_ptr	builtin;

	if ((builtin = get_internal_builtin_ptr(command->args[0])) != NULL)
		g_sh.status = (*builtin)((const char **)command->args);
	else if ((builtin = get_builtin_ptr(command->args[0])) != NULL)
		(*builtin)((const char **)command->args);
	else if (command->args[0] == NULL)
		exit(EXIT_SUCCESS);
	else if (ft_strchr(command->args[0], '/') && !is_executable(command))
		exit(g_sh.status);
	else if (command->bin_path != NULL
	&& !execve(command->bin_path, command->args, (char **)g_sh.env))
		exit(EXIT_FAILURE);
	exit(g_sh.status);
	return (0);
}

int				fork_command(t_command *pipeline, int *pfd, int in)
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

static int		must_exec(t_builtin_ptr b, t_command *p, t_command *f)
{
	if (!p->pipe && ((b == exit_builtin
	&& f == p) || b != exit_builtin))
		return (1);
	return (0);
}

static void		exec_internal_builtin(t_builtin_ptr to_exec, char **args)
{
	if (to_exec != exit_builtin)
		redirect_parent_to_null_on();
	g_sh.status = (*to_exec)((const char **)args);
	if (to_exec != exit_builtin)
		redirect_parent_to_null_off();
}

int				spawn_pipeline(t_command *pipeline)
{
	t_builtin_ptr	builtin;
	int				pfd[2];
	int				in;
	t_command		*first;

	first = pipeline;
	while (pipeline)
	{
		if ((builtin = get_internal_builtin_ptr(pipeline->args[0])) != NULL)
			if (must_exec(builtin, pipeline, first))
				exec_internal_builtin(builtin, pipeline->args);
		if (pipeline->redirections)
			redirection_hub(pipeline, pipeline->redirections);
		else if (builtin != exit_builtin)
		{
			fork_command(pipeline, pfd, in);
			in = pfd[0];
		}
		pipeline = pipeline->pipe;
	}
	return (set_signal());
}
