/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 18:56:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

enum e_token_type	get_token_type(char *c)
{
	if (ft_in_charset(c, TOKEN_OPERATOR))
		return (Token_operator);
	if (ft_in_charset(c, TOKEN_SEPARATOR))
		return (Token_separator);
	return (Token_literal);
}

t_list				*tokenize(char *input)
{
	t_list	*result;
	enum e_token_type type;
	int i;

	i = -1;
	while (input[++i])
	{
		if (ft_isspace(input[i]))
			continue;
		type = get_token_type(input[i]);
		
	}
	return (result);
}
