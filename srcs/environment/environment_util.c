/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 15:12:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_environment to_print)
{
	t_list *begin;
	
	begin = to_print.lst_var;
	while (begin)
	{
        ft_printf("%s\n", begin->content);
		begin = begin->next;
	}
}

void	lst_del_env_elem(void *variable)
{
	free(variable);
}
