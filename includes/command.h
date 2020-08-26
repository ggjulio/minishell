/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:37:23 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/25 17:27:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "minishell.h"

typedef struct	s_command
{
	char				*bin_path;
	char				**args;
	struct s_command	*pipe;
}				t_command;

/*
** command.c
*/
t_command		create_command(t_list *p_args);
t_command		*malloc_command(t_list *p_args);
void			destroy_command(t_command to_destroy);
void			free_command(t_command *to_free);

/*
** command_util.c
*/
char			*get_exec_path(char *exec_name);
void			print_command(t_command *to_print);
int				spawn_pipeline(t_command *command);

/*
** command_util.c
*/
void			lst_del_command(void *to_free);

/*
** command_check.c
*/
int     		check_commands(t_list *commands);

/*
** command_pipelines.c
*/
t_list			*get_pipelines(char * input);

#endif
