/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:52:21 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/05 22:49:41 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	create_shell(const char *name, t_environment envp)
{
	t_shell result;

	ft_bzero(&result, sizeof(t_shell));
	result.name = ft_strdup(name + 2);
	result.env = malloc_environment(envp);
	result.status = 0;
	result.running = 42;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	getcwd(result.cwd, sizeof(result.cwd));
	return (result);
}

t_shell	*malloc_shell(char *name, t_environment envp)
{
	t_shell *result;

	if ((result = malloc(sizeof(t_shell))) == NULL)
		return (NULL);
	*result = create_shell(name, envp);
	return (result);
}

void	destroy_shell(t_shell to_destroy)
{
	free_environment(to_destroy.env);
	free(to_destroy.name);
}

void	free_shell(t_shell *to_free)
{
	destroy_shell(*to_free);
	free(to_free);
}
