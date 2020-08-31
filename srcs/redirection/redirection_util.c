/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:48:43 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/31 16:19:44 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirection_type	get_redirection_type_from_token_type(t_token_type p_type)
{
	if (p_type == Token_op_dgreat)
		return (Redirection_dgreat);
	if (p_type == Token_op_great)
		return (Redirection_great);
	if (p_type == Token_op_less)
		return (Redirection_less);
	return (Redirection_None);
}

void				print_redirection(t_redirection *to_print)
{
	const char	str[7][20] = {"Redirection_None", "Redirection_great",
		"Redirection_dgreat", "Redirection_less"};

	ft_printf("redirection : \"%s\" | %s\n",
		to_print->str, str[to_print->type]);
}

void				print_lst_redirection(t_list *lst_to_print)
{
	while (lst_to_print)
	{
		print_redirection(lst_to_print->content);
		lst_to_print = lst_to_print->next;
	}
}
