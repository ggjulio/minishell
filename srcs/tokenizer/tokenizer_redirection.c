/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:58:47 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/30 21:00:06 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirection_detect_operator(t_list **begin_tokens)
{
	t_list	*iterator;
	t_token	*actual;
	t_token	*next;

	iterator = *begin_tokens;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (actual->type == Token_operator && ft_in_charset(actual->str[0], "<>"))
		{
			if (actual->str[0] == '>')
			{
				if (next->type == Token_operator && next->str[0] == '>')
				{
					iterator->content = merge_tokens(actual, next, Token_op_dgreat);
					ft_lstdelone(ft_lstpop_elem(begin_tokens, iterator->next), NULL);
					if (iterator->next == NULL)
						break ;
					next = iterator->next->content;
				}
				else
					actual->type = Token_op_great;
			}
			else if (actual->str[0] == '<')
			{
				actual->type = Token_op_less;
			}
			if (next->type != Token_literal)
				continue ;
		}
		iterator = iterator->next;
	}
}

void	redirection_join_arg(t_list **begin_tokens)
{
	t_list	*iterator;
	t_token	*actual;
	t_token	*next;
	t_list	*elem_to_del;

	iterator = *begin_tokens;
	while (iterator)
	{
		actual = iterator->content;
		if (iterator->next)
		{
			next = iterator->next->content;
			if (actual->type == Token_op_dgreat || actual->type == Token_op_great
				|| actual->type == Token_op_less)
			{
				if (next->type != Token_operator && next->type != Token_op_pipe)
				{
					next->type = actual->type;
				}
				else
				{
					ft_printf("TODO ! syntax error near unexpected token: %s\n", next->str);
				}
				
					elem_to_del = ft_lstpop_elem(begin_tokens, iterator);
					iterator = elem_to_del->next;
					ft_lstdelone(elem_to_del, lst_del_token);
			}
		}
		else if (actual->type == Token_op_dgreat || actual->type == Token_op_great
				|| actual->type == Token_op_less)
			ft_printf("error shit! redirection operator don't have file ");
		iterator = iterator->next;
	}
}
