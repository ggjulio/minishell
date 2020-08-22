/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:35:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 02:29:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

// typedef const char**	t_environment;
typedef char**	t_environment;

/*
**	environment.c
*/
t_environment			malloc_environment(char **envp);
void					free_environment(t_environment to_free);
size_t					environment_len(char **envp);

/*
**	environment_util.c
*/
void					print_env_array(void);
char					*get_env_var_value(char *name);
void					set_env_var_value(char *name, char *value);

#endif
