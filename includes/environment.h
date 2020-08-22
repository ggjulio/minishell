/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:35:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 14:06:41 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

// typedef const char**	t_environment;
typedef const char**	t_environment;

/*
**	environment.c
*/
t_environment			malloc_environment(char **envp);
void					free_environment(t_environment to_free);
void					add_environment_variable(char *variable);
size_t					environment_len(char **envp);

/*
**	environment_util.c
*/
void					print_environment(void);
char					*get_environment_variable(char *name);
char					*get_environment_variable_value(char *name);
void					set_environment_variable_value(char *name, char *value);

#endif
