/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 23:23:56 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_token_type	get_token_type(char c)
{
	if (ft_in_charset(c, TOKEN_OPERATOR))
		return (Token_operator);
	if (ft_in_charset(c, TOKEN_SEPARATOR))
		return (Token_separator);
	if (ft_in_charset(c, TOKEN_SPACE))
		return (Token_space);
	return (Token_literal);
}

void				print_tokens(t_list *lst)
{
	t_token		*token;
	static char str[5][15] = {"None", "literal", "operator",
								"separator", "space"};

	while (lst)
	{
		token = lst->content;
		ft_printf("%s : %s\n", token->str, str[token->type]);
		lst = lst->next;
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
	print_tokens(result);
	return (result);
}
