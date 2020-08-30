/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:37:23 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/30 12:10:41 by hwinston         ###   ########.fr       */
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
void			lst_del_command(void *to_free);

/*
** command_util.c
*/
char			*get_exec_path(char *exec_name);
void			print_command(t_command *to_print);
int             is_executable(t_command *command);

/*
** command_validation.c
*/
int				is_valid_pipeline(t_command *pipeline);

/*
** command_pipelines.c
*/
t_command		*get_pipeline(char *input);

/*
** command_spawn.c
*/
int				spawn_pipeline(t_command *command);

#endif
