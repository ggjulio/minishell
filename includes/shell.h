/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:54:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/30 23:43:26 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "minishell.h"

typedef struct		s_shell
{
	char			*name;
	t_environment	env;
	char			cwd[PATH_MAX + 1];
	int				status;
}					t_shell;

/*
** shell.c
*/
t_shell				create_shell(const char *name, t_environment envp);
t_shell				*malloc_shell(char *name, t_environment envp);
void				destroy_shell(t_shell to_destroy);
void				free_shell(t_shell *to_free);

/*
** shell_util.c
*/
void				run_shell(void);
void				execute_pipelines(t_list *commands);
void				sigint_handler(int sig);
void				sigquit_handler(int sig);

/*
**	shell_exit.c
*/
void				exit_shell(int status);

#endif
