/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_to_null.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:54:27 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/07 18:18:40 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	g_stdout_copy;
static int	g_stderr_copy;
static int	g_stdout_to_null;
static int	g_stderr_to_null;

void	redirect_parent_to_null_on(void)
{
	g_stdout_copy = dup(STDOUT_FILENO);
	g_stderr_copy = dup(STDERR_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	g_stdout_to_null = open("/dev/null", O_WRONLY);
	g_stderr_to_null = open("/dev/null", O_WRONLY);
}

void	redirect_parent_to_null_off(void)
{
	close(g_stdout_to_null);
	close(g_stderr_to_null);
	dup2(g_stdout_copy, STDOUT_FILENO);
	dup2(g_stderr_copy, STDERR_FILENO);
	close(g_stdout_copy);
	close(g_stderr_copy);
}
