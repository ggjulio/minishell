/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:38:36 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/02 19:31:01 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  open_file(t_redirection *r)
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

static int  fork_redirection(t_command *command, t_redirection *r, int fd)
{
    int pid;

    (void)command;

    if ((pid = fork()) == -1)
        return (-1);
    if (pid > 0)
        waitpid(pid, &g_sh.status, 0);
    if (pid == 0)
    {
        if (r->type == Redirection_less)
            redirect_pipe_end(fd, STDIN_FILENO);
        else
            redirect_pipe_end(fd, STDOUT_FILENO);
		run_command(command);
        exit(EXIT_FAILURE);
    }
    close(fd);
    return (0);
}

static int  skip_redirection(t_list *redirections)
{
    t_redirection *current;
    t_redirection *next;

    current = redirections->content;
    if (!redirections->next)
        return (0);
    else
        next = redirections->next->content;
    if ((current->type == Redirection_great || current->type == Redirection_dgreat))
        if (next->type == Redirection_great || next->type == Redirection_dgreat)
            return (1);
    return (0);
}

int         redirection_hub(t_command *command, t_list *redirections)
{
    t_list          *iterator;
    t_redirection   *current;
    int             fd;

    iterator = redirections;
    while (iterator)
    {
        current = iterator->content;
        if ((fd = open_file(current)) == -1)
        {
            error(command->args[0], current->str);
            return (-1);
        }
        if (!skip_redirection(iterator))
            fork_redirection(command, current, fd);
        close(fd);
        iterator = iterator->next;
    }
    return (0);
}