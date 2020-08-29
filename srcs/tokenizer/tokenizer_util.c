/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:32:18 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/29 22:56:35 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	get_token_type(char c)
{
	if (ft_in_charset(c, TOKEN_OPERATOR))
		return (c == '|' ? Token_op_pipe : Token_operator);
	if (ft_in_charset(c, TOKEN_QUOTE))
		return (Token_quote);
	if (ft_in_charset(c, TOKEN_SPACE))
		return (Token_space);
	if (ft_in_charset(c, TOKEN_VARIABLE))
		return (Token_variable);
	if (ft_in_charset(c, TOKEN_ESCAPE))
		return (Token_escape);
	return (Token_literal);
}

char			**lst_token_to_string_array(t_list *lst_strings)
{
	char	**result;
	int		i;

	if (!(result = malloc((ft_lstsize(lst_strings) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (lst_strings)
	{
		result[i++] = ft_strdup(lst_strings->content);
		lst_strings = lst_strings->next;
	}
	result[i] = 0;
	return (result);
}

int				is_between_simple_quote(t_list *begin_tokens, t_list *to_find)
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

void			remove_spaces(t_list **tokens)
{
	t_token *token_ref;

	token_ref = malloc_token("", Token_space);
	ft_lst_remove_if(tokens, token_ref, cmp_token_type, lst_del_token);
	free_token(token_ref);
}
