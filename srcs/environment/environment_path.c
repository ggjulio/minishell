/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:53:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 16:05:21 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**malloc_environment_path(void)
{
	char	**result;

	result = ft_split(get_environment_variable_value("$PATH"), ':');
	return (result);
}

void	free_environment_path(char **to_free)
{
	size_t i;

	i = 0;
	while (to_free[i])
		free(to_free[i++]);
	free(to_free);
}

void	print_environment_path(char **to_print)
{
	size_t i;

	i = 0;
	if (to_print == NULL)
	{
		ft_printf("\nEnvironment path array is NULL\n");
		return ;
	}
	while (to_print[i])
		ft_printf("%s\n", to_print[i++]);
}
