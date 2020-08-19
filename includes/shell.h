/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:54:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 15:49:56 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "minishell.h"

typedef struct	s_shell
{
	char			*name;
	t_environment	env;
}				t_shell;

/*
** shell.c
*/
t_shell			create_shell(char *name, char **envp);
t_shell			*malloc_shell(char *name, char **envp);
void			destroy_shell(t_shell to_destroy);
void			free_shell(t_shell *to_free);

/*
** shell_util.c
*/
void			run_shell(void);

/*
**	shell_exit.c
*/
void			exit_shell(int status);

#endif
