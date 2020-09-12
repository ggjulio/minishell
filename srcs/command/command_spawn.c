/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_spawn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:45:43 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/12 22:51:29 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		run_command(t_command *command)
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

static void		redirect_command(t_command *command, int in, int out)
{
	if (command->redirections)
		check_redirections(command->redirections, in, out);
	else
	{
		redirect_pipe_end(in, STDIN_FILENO);
		redirect_pipe_end(out, STDOUT_FILENO);
	}
	run_command(command);
}

static void		exec_last_commmand(t_command *command, int in, int out)
{
	pid_t	pid;

	if ((pid = fork()) == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		redirect_command(command, in, out);
}

static void		fork_command(t_command *command, int in, int *pfd)
{
	pid_t	pid;

	if ((pid = fork()) == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		close(pfd[R_END]);
		if (command->pipe)
			redirect_command(command, in, pfd[W_END]);
		else
			redirect_command(command, in, STDOUT_FILENO);
	}
}

int				spawn_pipeline(t_command *pipeline)
{
	const t_command		*first = pipeline;
	int					pfd[2];
	int					tmp_fd;

	tmp_fd = STDIN_FILENO;
	while (pipeline)
	{
		pipe(pfd);
		fork_command(pipeline, tmp_fd, pfd);
		close(pfd[W_END]);
		if (tmp_fd != 0)
			close(tmp_fd);
		tmp_fd = pfd[R_END];
		pipeline = pipeline->pipe;
	}
	set_signal();
	close(tmp_fd);
	run_internal_builtins((t_command *)first);
	return (0);
}
