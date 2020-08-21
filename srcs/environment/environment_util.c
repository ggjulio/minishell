/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/21 15:28:56 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void)
{
	t_list		*begin;
	t_env_var	*env_var;

	begin = g_sh.env.lst_var;
	while (begin)
	{
		env_var = begin->content;
		ft_printf("%s=%s\n", env_var->name, env_var->value);
		begin = begin->next;
	}
}

char	*get_env_var_value(char *name)
{
	t_list		*iterator;
	t_env_var	*env_var;

	iterator = g_sh.env.lst_var;
	if (name[0] == '$')
		name++;
	while (iterator)
	{
		env_var = iterator->content;
		if (!ft_strcmp(name, env_var->name))
			return (env_var->value);
		iterator = iterator->next;
	}
	return (NULL);
}

void	set_env_var_value(char *name, char *value)
{
	t_list		*iterator;
	t_env_var	*env_var;

	iterator = g_sh.env.lst_var;
	if (name[0] == '$')
		name++;
	while (iterator)
	{
		env_var = iterator->content;
		if (!ft_strcmp(name, env_var->name))
		{
			free(env_var->value);
			env_var->value = ft_strdup(value);
			return ;
		}
		iterator = iterator->next;
	}
}
