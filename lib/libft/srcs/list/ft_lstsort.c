/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:25:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 17:11:03 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_actual_and_next(t_list *actual)
{
	t_list	*tmp;

	tmp = actual->next;
	actual->next = actual->next->next;
	tmp->next = actual;
}

void		ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list *previous;
	t_list *actual;

	previous = NULL;
	actual = *begin_list;
	if (actual == NULL)
		return ;
	while (actual->next)
	{
		if (cmp(actual->content, actual->next->content) > 0)
		{
			if (previous != NULL)
				previous->next = actual->next;
			else
				*begin_list = actual->next;
			swap_actual_and_next(actual);
			previous = NULL;
			actual = *begin_list;
			continue;
		}
		previous = actual;
		actual = actual->next;
	}
}
