/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:00:10 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/01 16:27:02 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "minishell.h"

typedef enum	e_redirection_type
{
	Redirection_None,
	Redirection_great,
	Redirection_dgreat,
	Redirection_less,
}				t_redirection_type;

typedef struct	s_redirection
{
	char				*str;
	t_redirection_type	type;
}				t_redirection;

/*
** redirection.c
*/
t_redirection	create_redirection
					(char *p_filename, t_redirection_type p_type);
t_redirection	*malloc_redirection
					(char *p_filename, t_redirection_type p_type);
void			destroy_redirection(t_redirection to_destroy);
void			free_redirection(t_redirection *to_free);
void			lst_del_redirection(void *to_free);

/*
** redirection_util.c
*/
t_redirection_type	get_redirection_type_from_token_type(t_token_type p_type);
void			print_redirection(t_redirection *to_print);
void			print_lst_redirection(t_list *lst_to_print);

/*
** redirection_handle.c
*/
int         	redirection_hub(t_command *command, t_list *redirections);

#endif
