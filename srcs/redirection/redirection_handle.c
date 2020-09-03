/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:38:36 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/03 12:49:28 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int      open_file(t_redirection *r)
{
    int fd;

    fd = 0;
    if (r->type == Redirection_great)
        fd = open(r->str, O_WRONLY | O_TRUNC | O_CREAT, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    else if (r->type == Redirection_dgreat)
        fd = open(r->str, O_WRONLY | O_APPEND | O_CREAT, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    else if (r->type == Redirection_less)
        fd = open(r->str, O_RDONLY);
    return (fd);
}

static void     set_fds(t_list *r, int *fdin, int *fdout)
{
    t_list          *last;
    t_redirection   *content;
    t_redirection   *last_content;
    
    content = r->content;
    last = ft_lstlast(r);
    last_content = last->content;
    
    if (content->type == Redirection_less)
        *fdin = open_file(content);
    else
        *fdin = STDIN_FILENO;
    if (last_content->type != Redirection_less)
        *fdout = open_file(last->content);
    else
        *fdout = STDOUT_FILENO;
}

static int      fork_redirection(t_command *command, int fdin, int fdout)
{
    int pid;

    if ((pid = fork()) == -1)
        return (-1);
    if (pid == 0)
    {
        redirect_pipe_end(fdin, STDIN_FILENO);
        redirect_pipe_end(fdout, STDOUT_FILENO);
		run_command(command);
        exit(EXIT_FAILURE);
    }
    waitpid(pid, &g_sh.status, 0);
    close(fdin);
    close(fdout);
    return (0);
}

int             redirection_hub(t_command *command, t_list *r)
{
    t_list      *iterator;
    int         fdin;
    int         fdout;
    int         fd;

    //(void)command;

    iterator = r;
    set_fds(iterator, &fdin, &fdout);
    if (fdin > 0 && iterator->next)
        iterator = iterator->next;
    ft_dprintf(2, " IN = %d | OUT = %d\n", fdin, fdout);
    while (iterator)
    {
        fd = open_file(iterator->content);
        close(fd);
        iterator = iterator->next;
    }
    fork_redirection(command, fdin, fdout);
    return (0);
}