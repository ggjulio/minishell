/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:38:36 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/12 22:53:36 by hwinston         ###   ########.fr       */
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

static int		get_fdin_position(t_list *r)
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

static int		get_fdout_position(t_list *r)
{
	t_redirection	*content;
	int				i;
	int				j;

	content = r->content;
	i = 0;
	while (r->next && content->type == Redirection_less)
	{
		r = r->next;
		content = r->content;
		i++;
	}
	j = 0;
	while (r->next && content->type != Redirection_less)
	{
		r = r->next;
		content = r->content;
		j++;
	}
	if (j == 0 && content->type == Redirection_less)
		return (-1);
	if (content->type == Redirection_less)
		i--;
	return (i + j);
}

void			check_redirections(t_list *redirections, int in, int out)
{
	int		fd[ft_lstsize(redirections)];
	int		fd_pos[2];
	int		i;

	if ((fd_pos[W_END] = get_fdin_position(redirections)) == -1)
		redirect_pipe_end(in, STDIN_FILENO);
	if ((fd_pos[R_END] = get_fdout_position(redirections)) == -1)
		redirect_pipe_end(out, STDOUT_FILENO);
	i = 0;
	while (redirections)
	{
		if ((fd[i] = open_file(redirections->content)) == -1)
			return ;
		if (i != fd_pos[R_END] && i != fd_pos[W_END])
			close(fd[i]);
		else if (i == fd_pos[W_END])
			redirect_pipe_end(fd[i], in);
		else if (i == fd_pos[R_END])
			redirect_pipe_end(fd[i], out);
		redirections = redirections->next;
		i++;
	}
}
