/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/25 18:50:42 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				concatenate_literals(t_list **tokens)
{
	t_list	*iterator;
	t_token	*actual;
	t_token	*next;

	iterator = *tokens;
	if (iterator == NULL)
		return ;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (actual->type == next->type && actual->type == Token_literal)
		{
			iterator->content = merge_tokens(actual, next, actual->type);
			ft_lstdelone(ft_lstpop_elem(tokens, iterator->next), NULL);
		}
		else
			iterator = iterator->next;
	}
}

void				concatenate_variables(t_list **tokens)
{
	t_list	*iterator;
	t_token	*actual;
	t_token	*next;

	iterator = *tokens;
	if (iterator == NULL)
		return ;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (actual->type == Token_variable && next->type == Token_literal)
		{
			iterator->content = merge_tokens(actual, next, actual->type);
			ft_lstdelone(ft_lstpop_elem(tokens, iterator->next), NULL);
		}
		else
			iterator = iterator->next;
	}
}

int					cmp_token_type(t_token *t1, t_token *t2)
{
	return (t1->type != t2->type);
}



void				manage_quotes(t_list **tokens)
{
	t_list	*iterator;
	t_token	*actual;
	int		has_open_quote;
	char	quote_type;
	t_token	*token_ref;


	iterator = *tokens;
	if (iterator == NULL)
		return ;
	has_open_quote = 0;
	while (iterator)
	{
		actual = iterator->content;
		if (actual->type == Token_quote && !has_open_quote)
		{
			has_open_quote = 1;
			quote_type = actual->str[0];
		}
		else if (actual->type == Token_quote && quote_type == actual->str[0])
			has_open_quote = 0;
		else if (has_open_quote)
			actual->type = Token_literal;
		iterator = iterator->next;
	}
	token_ref = malloc_token("", Token_quote);
	ft_lst_remove_if(tokens, token_ref, cmp_token_type, lst_del_token);
	free_token(token_ref);
}

void				remove_spaces(t_list **tokens)
{
	t_token *token_ref;

	token_ref = malloc_token("", Token_space);
	ft_lst_remove_if(tokens, token_ref, cmp_token_type, lst_del_token);
	free_token(token_ref);
}

void				do_escape(t_list **tokens)
{
	t_list	*iterator;
	t_token	*actual;
	t_token	*next;
	t_list 	*elem_to_del;

	iterator = *tokens;
	if (iterator == NULL)
		return ;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (actual->type == Token_escape)
		{
			next->type = Token_literal;
			elem_to_del = ft_lstpop_elem(tokens, iterator);
			iterator = elem_to_del->next;
			ft_lstdelone(elem_to_del, lst_del_token);
		}
		else
			iterator = iterator->next;
	}
}

t_list				*tokenize(char *input)
{
	t_list	*result;
	char	one_char[2];
	int		i;

	i = -1;
	result = NULL;
	ft_bzero(&one_char, 2);
	while (input[++i])
	{
		one_char[0] = input[i];
		ft_lstadd_back(&result, ft_lstnew(
				malloc_token(one_char, get_token_type(one_char[0]))));
	}
		// print_lst_tokens(result);
	do_escape(&result);
		// ft_printf("###########################################\n");
		// print_lst_tokens(result);
	manage_quotes(&result);
	concatenate_literals(&result);
	concatenate_variables(&result);
	remove_spaces(&result);
	return (result);
}
