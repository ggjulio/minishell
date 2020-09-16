/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:58:47 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/16 23:18:31 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirection_case_last_is_redirection(t_list *last)
{
	t_token	*last_tok;

	if (last == NULL)
		return ;
	last_tok = last->content;
	if (last_tok == NULL || last_tok->type != Token_operator)
		return ;
	if (last_tok->str[0] == '>')
		last_tok->type = Token_op_great;
	else if (last_tok->str[0] == '<')
		last_tok->type = Token_op_less;
}

static int	norm_detect_operator(t_list **begin_tokens,
				t_list **iterator, t_token **actual, t_token **next)
{
	if ((*actual)->str[0] == '>')
	{
		if ((*next)->type == Token_operator && (*next)->str[0] == '>')
		{
			(*iterator)->content =
				merge_tokens((*actual), *next, Token_op_dgreat);
			ft_lstdelone(
				ft_lstpop_elem(begin_tokens, (*iterator)->next), NULL);
			if ((*iterator)->next == NULL)
				return (1);
			(*next) = (*iterator)->next->content;
		}
		else
			(*actual)->type = Token_op_great;
	}
	else if ((*actual)->str[0] == '<')
		(*actual)->type = Token_op_less;
	return (0);
}

void		redirection_detect_operator(t_list **begin_tokens)
{
	t_list	*iterator;
	t_token	*actual;
	t_token	*next;

	iterator = *begin_tokens;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (actual->type == Token_operator
		&& ft_in_charset(actual->str[0], "<>"))
		{
			if (norm_detect_operator(begin_tokens, &iterator, &actual, &next))
				break ;
			if (next->type != Token_literal)
				continue ;
		}
		iterator = iterator->next;
	}
	redirection_case_last_is_redirection(iterator);
}

static int	norm_join_arg(
			t_list **begin_tokens, t_list **iterator, t_token **actual)
{
	t_token	*next;
	t_list	*elem_to_del;

	if ((*iterator)->next)
	{
		next = (*iterator)->next->content;
		if ((*actual)->type == Token_op_dgreat
	|| (*actual)->type == Token_op_great || (*actual)->type == Token_op_less)
		{
			if (next->type == Token_literal)
				next->type = (*actual)->type;
			else if ((*actual)->type == Token_op_less)
				syntax_error("<");
			else
				syntax_error((*actual)->type == Token_op_dgreat ? ">>" : ">");
			elem_to_del = ft_lstpop_elem(begin_tokens, *iterator);
			*iterator = elem_to_del->next;
			ft_lstdelone(elem_to_del, lst_del_token);
		}
		return (1);
	}
	return (0);
}

void		redirection_join_arg(t_list **begin_tokens)
{
	t_list	*iterator;
	t_token	*actual;

	iterator = *begin_tokens;
	while (iterator)
	{
		actual = iterator->content;
		if (norm_join_arg(begin_tokens, &iterator, &actual))
			;
		else if (actual->type == Token_op_dgreat
		|| actual->type == Token_op_great || actual->type == Token_op_less)
		{
			if (actual->type == Token_op_less)
				syntax_error("<");
			else
				syntax_error(actual->type == Token_op_dgreat ? ">>" : ">");
		}
		iterator = iterator->next;
	}
}
