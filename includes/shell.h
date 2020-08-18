/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:54:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/18 18:05:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

#include "minishell.h"

typedef struct	s_shell
{
	char *name;
	t_environment env;
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

#endif
