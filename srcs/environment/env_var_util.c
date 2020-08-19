/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:19:26 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 17:20:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_del_env_elem(void *to_free)
{
	free_env_var(to_free);
}

int		cmp_sort(t_env_var *s1, t_env_var *s2)
{
	return (ft_strcmp(s1->name, s2->name));
}
