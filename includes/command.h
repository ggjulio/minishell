/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:37:23 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/20 00:53:04 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "minishell.h"

# define R_END	0
# define W_END	1

typedef struct	s_command
{
	char				*bin_path;
	char				**args;
	t_list				*redirections;
	struct s_command	*pipe;
}				t_command;

/*
** command.c
*/
t_command		create_command(t_list *p_args, t_list *p_redirections);
t_command		*malloc_command(t_list *p_args, t_list *p_redirections);
void			destroy_command(t_command to_destroy);
void			free_command(t_command *to_free);
void			lst_del_command(void *to_free);

/*
** command_util.c
*/
char			*get_exec_path(char *exec_name);
void			print_command(t_command *to_print);
int				is_executable(t_command *command);

/*
** command_pipelines.c
*/
t_command		*get_pipeline(char *input);

/*
** command_spawn.c
*/
int				spawn_pipeline(t_command *command);

/*
** command_builtins.c
*/
int				run_internal_builtins(t_command *pipeline);

#endif
