/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:02:03 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/20 15:08:19 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print(t_list *lst, void (*print_content)(void*))
{
	int i;

	i = 1;
	if (lst == NULL)
		ft_printf("	Empty list !\n");
	while (lst)
	{
		ft_printf("   %d : %p\n", i, lst);
		ft_printf("       data : \n");
		if (lst)
			print_content(lst->content);
		else
			ft_printf("            NULL\n");
		ft_printf("       next : \"%p\"\n\n", lst ? lst->next : 0);
		i++;
		lst = lst->next;
	}
}
