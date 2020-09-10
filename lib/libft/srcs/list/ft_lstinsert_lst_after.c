/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_lst_after.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:01:04 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/10 18:08:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert_lst_after(t_list *after_node, t_list *lst_to_insert)
{
	t_list *iterator;

	iterator = lst_to_insert;
	while (iterator)
	{
		if (iterator->next == NULL)
		{
			iterator->next = after_node->next;
			break ;
		}
		iterator = iterator->next;
	}
	after_node->next = lst_to_insert;
}
