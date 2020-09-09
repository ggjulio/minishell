/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:15:59 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/09 18:23:58 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_quotes(t_list **tokens)
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
	if (has_open_quote)
		syntax_error((char[2]){quote_type, '\0'});
}

void	manage_empty_quotes(t_list **begin_list)
{
	t_list	*iterator;
	t_token *actual;
	t_token *next;

	iterator = *begin_list;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (actual->type == Token_quote && actual->type == Token_quote)
		{
			free(actual->str);
			actual->str = ft_strdup("");
			actual->type = Token_literal;
			iterator = iterator->next;
		}
		iterator = iterator->next;
	}
}
