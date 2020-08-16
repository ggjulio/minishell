/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:54:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/16 17:01:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLICATION_H
# define APPLICATION_H

typedef struct	s_application
{
	char **env_var;
}				t_application;

/*
** application.c
*/
t_application	create_application(char **envp);
t_application	*malloc_application(char **envp);
void			destroy_application(t_application to_destroy);
void			free_application(t_application *to_free);

#endif
