/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:30:21 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/19 15:48:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	validation_backslash(t_list *begin_list)
{
	int		has_error;
	t_list	*iterator;
	t_token	*actual;

	iterator = begin_list;
	actual = NULL;
	has_error = 0;
	while (iterator)
	{
		actual = iterator->content;
		has_error = (actual->type == Token_escape) ? 1 : 0;
		iterator = iterator->next;
	}
	if (has_error)
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
