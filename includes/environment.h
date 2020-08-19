/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:35:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 15:50:02 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

typedef struct	s_environment
{
	t_list		*lst_var;
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
t_environment	*malloc_environment(char **envp);
void			destroy_environment(t_environment to_destroy);
void			free_environment(t_environment *to_free);

/*
**	env_var.c
*/
t_env_var		create_env_var(char *env_var);
t_env_var		*malloc_env_var(char *env_var);
void			destroy_env_var(t_env_var to_destroy);
void			free_env_var(t_env_var *to_free);
void			lst_del_env_elem(void *variable);

/*
**	environment_util.c
*/
void			print_env(t_environment to_print);

#endif
