/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:41:28 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/12 23:11:06 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

# define NOT_VALID_CHARS_IN_VAR " \\\"'$@!&|;"

typedef int		(*t_builtin_ptr)(const char **args);

int				echo(const char **args);
int				cd(const char **args);
int				pwd(const char **args);
int				export(const char **args);
int				env(const char **args);
int				unset(const char **args);
int				exit_builtin(const char **args);

/*
** builtins_util.c
*/
t_builtin_ptr	get_builtin_ptr(char *command_name);
t_builtin_ptr	get_internal_builtin_ptr(char *command_name);

#endif
