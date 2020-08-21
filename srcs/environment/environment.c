/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:34:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 01:17:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char 	**create_env_array(t_list *lst_env)
{
	char		**result;
	size_t		i;
	char		*tmp;
	t_env_var	*env_var;

	if (!(result = malloc((ft_lstsize(lst_env) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (lst_env)
	{
		env_var = lst_env->content;
		tmp = ft_strdupcat(env_var->name, "=");
		result[i] = ft_strdupcat(tmp, env_var->value);
		free(tmp);
		i++;
		lst_env = lst_env->next;
	}
	result[i] = NULL;
	return (result);
}

t_environment	create_environment(char **envp)
{
	t_environment result;

	result.lst_var = NULL;
	while (*envp != 0)
	{
		ft_lstadd_back(&(result.lst_var),
			ft_lstnew(malloc_env_var(*envp)));
		envp++;
	}
	result.array = create_env_array(result.lst_var);
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

void			destroy_environment(t_environment to_destroy)
{
	ft_lstclear(&to_destroy.lst_var, lst_del_env_elem);
}

void			free_environment(t_environment *to_free)
{
	destroy_environment(*to_free);
	free(to_free);
}
