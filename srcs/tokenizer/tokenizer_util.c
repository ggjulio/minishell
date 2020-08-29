/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:32:18 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/29 20:55:51 by juligonz         ###   ########.fr       */
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
