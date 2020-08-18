/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:54:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/18 13:23:11 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

typedef struct	s_shell
{
	char *name;
	char **env_var;
}				t_shell;

/*
** shell.c
*/
t_shell			create_shell(char *name, char **envp);
t_shell			*malloc_shell(char *name, char **envp);
void			destroy_shell(t_shell to_destroy);
/*
** shell_util.c
*/
void			run_shell();

#endif
