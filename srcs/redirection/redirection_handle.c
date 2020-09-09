/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:38:36 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/09 15:30:26 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		open_file(t_redirection *r)
{
	int fd;

	fd = 0;
	if (r->type == Redirection_great)
		fd = open(r->str, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (r->type == Redirection_dgreat)
		fd = open(r->str, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else if (r->type == Redirection_less)
		fd = open(r->str, O_RDONLY);
	if (fd == -1)
		error("", r->str);
	return (fd);
}

static int		get_fdin_pos(t_list *r)
{
	t_redirection	*content;
	int				i;

	content = r->content;
	if (content->type != Redirection_less)
		return (-1);
	i = 0;
	while (r && content->type == Redirection_less)
	{
		if ((r = r->next) != NULL)
		{
			content = r->content;
			if (content->type == Redirection_less)
				i++;
		}
	}
	return (i);
}

static int		get_fdout_pos(t_list *r)
{
	t_redirection	*content;
	int				i;

	content = r->content;
	i = 0;
	while (r->next && content->type == Redirection_less)
	{
		r = r->next;
		content = r->content;
		i++;
	}
	while (r->next && content->type != Redirection_less)
	{
		r = r->next;
		content = r->content;
		i++;
	}
	if (i == 0 && content->type == Redirection_less)
		return (-1);
	if (content->type == Redirection_less)
		i--;
	return (i);
}

static int		fork_redirection(t_command *command, int fdin, int fdout)
{
	int pid;

	if ((pid = fork()) == -1)
		return (-1);
	if (pid == 0)
	{
		if (fdin != STDIN_FILENO)
			redirect_pipe_end(fdin, STDIN_FILENO);
		if (fdout != STDOUT_FILENO)
			redirect_pipe_end(fdout, STDOUT_FILENO);
		run_command(command);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &g_sh.status, 0);
	return (0);
}

int				redirection_hub(t_command *command, t_list *r, int in)
{
	int		fd[ft_lstsize(r)];
	int		fdpos[2];
	int		pfd[2];
	int		i;

	if ((fdpos[0] = get_fdin_pos(r)) == -1)
		pfd[0] = in;
	if ((fdpos[1] = get_fdout_pos(r)) == -1)
		pfd[1] = 1;
	i = 0;
	while (r)
	{
		if ((fd[i] = open_file(r->content)) == -1)
			return (-1);
		if (i != fdpos[0] && i != fdpos[1])
			close(fd[i]);
		else if (i == fdpos[0])
			pfd[0] = fd[i];
		else if (i == fdpos[1])
			pfd[1] = fd[i];
		r = r->next;
		i++;
	}
	fork_redirection(command, pfd[0], pfd[1]);
	return (0);
}
