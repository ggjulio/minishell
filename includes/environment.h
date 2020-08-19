/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:35:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 14:25:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVIRONMENT_H
# define EVIRONMENT_H

#include "minishell.h"

typedef struct	s_environment
{
	t_list		*lst_env_var;
}				t_environment;

typedef struct	s_env_var
{
	char	*name;
	char	*value;
}				t_env_var;

/*
**	environment.c
*/
t_environment	create_environment(char **envp);
void			destroy_environment(t_environment to_destroy);
void			destroy_environment(t_environment to_destroy);
void			free_environment(t_environment *to_free);
void			lst_del_env_elem(void *variable);



#endif
