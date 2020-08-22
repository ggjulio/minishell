/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:35:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 16:03:02 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

typedef const char**	t_environment;

/*
**	environment.c
*/
t_environment			malloc_environment(t_environment envp);
void					free_environment(t_environment to_free);
void					add_environment_variable(char *variable);
size_t					environment_len(t_environment envp);

/*
**	environment_util.c
*/
void					print_environment(void);
const char				*get_environment_variable(char *name);
const char				*get_environment_variable_value(char *name);
void					set_environment_variable_value(char *name, char *value);

/*
**	environment_path.c
*/
char					**malloc_environment_path(void);
void					free_environment_path(char **to_free);
void					print_environment_path(char **to_print);

#endif
