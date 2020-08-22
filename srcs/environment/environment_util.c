/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 02:26:28 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_array(void)
{
	int i;

	i = 0;
	if (g_sh.env == NULL)
	{
		ft_printf("\nEnvironment array is NULL\n");
		return ;
	}
	while (g_sh.env[i])
		ft_printf("%s\n", g_sh.env[i++]);
}

// char	*get_env_var_value(char *name)
// {

// }

// void	set_env_var_value(char *name, char *value)
// {

// }
