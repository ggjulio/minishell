/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/10 17:58:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*assign_token_type_to_each_char(char *input)
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
	return (result);
}

void	do_escape(t_list **begin_tokens)
{
	t_list	*iterator;
	t_token	*actual;
	t_token	*next;
	t_list	*elem_to_del;

	iterator = *begin_tokens;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (actual->type == Token_escape)
		{
			if (!is_between_simple_quote(*begin_tokens, iterator))
			{
				next->type = Token_literal;
				elem_to_del = ft_lstpop_elem(begin_tokens, iterator);
				iterator = elem_to_del->next;
				ft_lstdelone(elem_to_del, lst_del_token);
			}
			else
				actual->type = Token_literal;
		}
		else
			iterator = iterator->next;
	}
}

void	concatenate_literals(t_list **tokens)
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

t_list	*tokenize(char *input)
{
	t_list	*result;

	result = assign_token_type_to_each_char(input);
	do_escape(&result);
	concatenate_variables(&result);
	expand_variables(&result);
	remove_tokens_type(&result, Token_variable);
	manage_quotes(&result);
	manage_empty_quotes(&result);
	remove_tokens_type(&result, Token_quote);
	concatenate_literals(&result);
	remove_tokens_type(&result, Token_space);
	redirection_detect_operator(&result);
	redirection_join_arg(&result);
	validation_tokens(result);
	if (has_syntax_error(-1))
	{
		ft_lstclear(&result, lst_del_token);
		return (NULL);
	}
	return (result);
}
