/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:32:18 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/16 20:57:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				in_simple_quote(t_list *begin_tokens, t_list *to_find)
{
	t_token	*actual;
	int		has_open_quote;
	char	quote_type;

	has_open_quote = 0;
	while (begin_tokens)
	{
		actual = begin_tokens->content;
		if (actual->type == Token_quote && !has_open_quote)
		{
			has_open_quote = 1;
			quote_type = actual->str[0];
		}
		else if (actual->type == Token_quote && quote_type == actual->str[0])
			has_open_quote = 0;
		if (begin_tokens == to_find)
		{
			if (has_open_quote && quote_type == '\'')
				return (1);
			return (0);
		}
		begin_tokens = begin_tokens->next;
	}
	return (-1);
}

int				in_double_quote(t_list *begin_tokens, t_list *to_find)
{
	t_token	*actual;
	int		has_open_quote;
	char	quote_type;

	has_open_quote = 0;
	while (begin_tokens)
	{
		actual = begin_tokens->content;
		if (actual->type == Token_quote && !has_open_quote)
		{
			has_open_quote = 1;
			quote_type = actual->str[0];
		}
		else if (actual->type == Token_quote && quote_type == actual->str[0])
			has_open_quote = 0;
		if (begin_tokens == to_find)
		{
			if (has_open_quote && quote_type == '"')
				return (1);
			return (0);
		}
		begin_tokens = begin_tokens->next;
	}
	return (-1);
}
