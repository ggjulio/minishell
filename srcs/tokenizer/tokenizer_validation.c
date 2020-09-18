/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:30:21 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/18 20:54:11 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	validation_backslash(t_list *begin_list)
{
	t_list	*iterator;
	t_token	*actual;

	iterator = begin_list;
	actual = NULL;
	while (iterator)
	{
		actual = iterator->content;
		iterator = iterator->next;
	}
	if (actual && actual->type == Token_escape)
		syntax_error("\\");
}

void	validation_pipes(t_list *begin_list)
{
	t_list	*iterator;
	t_list	*previous;
	t_token	*actual_tok;
	t_token	*next_tok;

	previous = NULL;
	iterator = begin_list;
	while (iterator)
	{
		actual_tok = iterator->content;
		next_tok = iterator->next ? iterator->next->content : NULL;
		if (actual_tok->type == Token_op_pipe)
			if (previous == NULL
			|| next_tok == NULL
			|| next_tok->type == Token_op_pipe)
				return (syntax_error("|"));
		previous = iterator;
		iterator = iterator->next;
	}
}

void	validation_tokens(t_list *begin_list)
{
	validation_backslash(begin_list);
	validation_pipes(begin_list);
}
