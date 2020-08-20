/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:02:50 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/20 15:08:28 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstpop_elem(t_list **begin_list, t_list *elem)
{
	t_list	*previous;
	t_list	*actual;

	previous = NULL;
	actual = *begin_list;
	while (actual)
	{
		if (actual != elem)
			previous = actual;
		else
		{
			if (previous == NULL)
				*begin_list = actual->next;
			else
				previous->next = actual->next;
			return (actual);
		}
		actual = actual->next;
	}
	return (NULL);
}
