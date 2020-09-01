/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:38:36 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/01 13:37:04 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int         open_file(t_redirection *r)
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

int         redirection_hub(t_command *command, t_redirection *r)
{
    int fd;
    int pid;

    if ((fd = open_file(r)) == -1)
    {
        error(command->args[0], r->str);
        return (-1);
    }
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
