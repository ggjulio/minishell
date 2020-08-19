/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 15:52:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_environment to_print)
{
	t_list		*begin;
	t_env_var	*env_var;

	begin = to_print.lst_var;
	while (begin)
	{
		env_var = begin->content;
		ft_printf("%s=%s\n", env_var->name, env_var->value);
		begin = begin->next;
	}
}
