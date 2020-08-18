/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:34:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/18 18:50:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_lst_env_var(t_list **lst, char **envp)
{
	char **tmp;

    for(tmp = envp; *tmp != 0; tmp++)
    {
        char *thisEnv = *tmp;
        ft_printf("%s\n", thisEnv);
    }
}

t_environment	create_environment(char **envp)
{
	t_environment result;

	init_lst_env_var(&result.lst_env_var, envp);
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
	(void)to_destroy;
}

void	free_environment(t_environment *to_free)
{
	destroy_environment(*to_free);
	free(to_free);
}

