/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:34:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 14:32:06 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void)
{
	t_list *begin;
	
	begin = g_sh.env.lst_env_var;
	while (begin)
	{
        ft_printf("%s\n", begin->content);
		begin = begin->next;
	}
}

t_environment	create_environment(char **envp)
{
	t_environment result;

	result.lst_env_var = NULL;
	while (*envp != 0)
	{
		ft_lstadd_back(&(result.lst_env_var),
			ft_lstnew(ft_strdup(*envp)));
		envp++;
    }
	print_env();
	return (result);
}

t_environment	*malloc_environment(char **envp)
{
	t_environment *result;

	if ((result = malloc(sizeof(t_environment))) == NULL)
		return (NULL);
	*result = create_environment(envp);
	return (result);
}

void	destroy_environment(t_environment to_destroy)
{
	ft_lstclear(&to_destroy.lst_env_var, lst_del_env_elem);
	(void)to_destroy;
}

void	free_environment(t_environment *to_free)
{
	destroy_environment(*to_free);
	free(to_free);
}

void lst_del_env_elem(void *variable)
{
	free(variable);
}