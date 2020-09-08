/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_split_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:09:07 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/09 00:14:55 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		split_do_escape(t_list **begin_tokens)
{
	t_list	*iterator;
	t_token	*actual;
	t_token	*next;

	iterator = *begin_tokens;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (actual->type == Token_escape)
		{
			if (!is_between_simple_quote(*begin_tokens, iterator))
				next->type = Token_literal;
			actual->type = Token_literal;
		}
		iterator = iterator->next;
	}
}

static void		split_manage_quotes(t_list **tokens)
{
	t_list	*iterator;
	t_token	*actual;
	int		has_open_quote;
	char	quote_type;

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
	// if (has_open_quote)
	// 	syntax_error((char[2]){quote_type, '\0'});
}

static void		concatenate_commands(t_list **tokens)
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
		if (actual->type != Token_end && next->type != Token_end)
		{
			iterator->content = merge_tokens(actual, next, actual->type);
			ft_lstdelone(ft_lstpop_elem(tokens, iterator->next), NULL);
		}
		else
			iterator = iterator->next;
	}
}


char	**split_input(char *input)
{
	char	**result;
	t_list	*pipelines;

	pipelines = assign_token_type_to_each_char(input);
	split_do_escape(&pipelines);
	split_manage_quotes(&pipelines);
	// print_lst_tokens(pipelines);
	concatenate_commands(&pipelines);
	// ft_printf("################\n");
	// print_lst_tokens(pipelines);
	remove_tokens_type(&pipelines, Token_end);
	// if (has_syntax_error(-1))
	// {
		
	// 	ft_lstclear(&pipelines, lst_del_token);
	// 	return (NULL);
	// }
	result = lst_token_to_string_array(pipelines);
	ft_lstclear(&pipelines, lst_del_token);
	return (result);
}
