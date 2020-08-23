/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:37:23 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/23 14:11:43 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "minishell.h"

typedef struct	s_command
{
	char	*bin_path;
	char	**args;
}				t_command;

/*
** command.c
*/
t_command		create_command(char **args);
t_command		*malloc_command(char **args);
void			destroy_command(t_command to_destroy);
void			free_command(t_command *to_free);

/*
** command_util.c
*/
char			*get_exec_path(char *exec_name);

#endif
