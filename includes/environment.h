/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:35:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 00:55:55 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

typedef struct	s_environment
{
	t_list		*lst_var;
	char		**array;
}				t_environment;

/*
**	environment.c
*/
t_environment	create_environment(char **envp);
t_environment	*malloc_environment(char **envp);
void			destroy_environment(t_environment to_destroy);
void			free_environment(t_environment *to_free);

/*
**	environment_util.c
*/
void			print_env_list(void);
void			print_env_array(void);
char			*get_env_var_value(char *name);
void			set_env_var_value(char *name, char *value);
void			update_env_array(void);

typedef struct	s_env_var
{
	char	*name;
	char	*value;
}				t_env_var;

/*
**	env_var.c
*/
t_env_var		create_env_var(char *env_var);
t_env_var		*malloc_env_var(char *env_var);
void			destroy_env_var(t_env_var to_destroy);
void			free_env_var(t_env_var *to_free);

/*
**	env_var_util.c
*/
void			lst_del_env_elem(void *variable);
int				cmp_sort(t_env_var *s1, t_env_var *s2);

#endif
