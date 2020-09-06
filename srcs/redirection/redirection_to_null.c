/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_to_null.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:54:27 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/06 19:22:25 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int stdout_copy;
static int stderr_copy;
static int stdout_to_null;
static int stderr_to_null;

void	redirect_parent_to_null_on(void)
{
	stdout_copy = dup(STDOUT_FILENO);
	stderr_copy = dup(STDERR_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	stdout_to_null = open("/dev/null", O_WRONLY);
	stderr_to_null = open("/dev/null", O_WRONLY);
}

void	redirect_parent_to_null_off(void)
{
	close(stdout_to_null);
	close(stderr_to_null);
	dup2(stdout_copy, STDOUT_FILENO);
	dup2(stderr_copy, STDERR_FILENO);
	close(stdout_copy);
	close(stderr_copy);
}