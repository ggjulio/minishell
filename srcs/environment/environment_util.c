/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 01:04:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_list(void)
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
void	print_env_array(void)
{
	int i;

	i = 0;
	if (g_sh.env.array == NULL)
	{
		ft_printf("\nenvironment array is NULL\n");
		return ;
	}
	while (g_sh.env.array[i])
		ft_printf("%s\n", g_sh.env.array[i++]);
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

void	update_env_array(void)
{
	char		**result;
	t_list		*iterator;
	size_t		i;
	char		*tmp;
	t_env_var	*env_var;

	if (g_sh.env.array != NULL)
		free(g_sh.env.array);
	g_sh.env.array = NULL;
	iterator = g_sh.env.lst_var;
	if (!(result = malloc((ft_lstsize(iterator) + 1) * sizeof(char *))))
		return ;
	i = 0;
	while (iterator)
	{
		env_var = iterator->content;
		tmp = ft_strdupcat(env_var->name, "=");
		result[i] = ft_strdupcat(tmp, env_var->value);
		free(tmp);
		i++;
		iterator = iterator->next;
	}
	result[i] = NULL;
	g_sh.env.array = result;
}
