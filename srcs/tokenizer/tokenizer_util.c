/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:32:18 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/29 16:29:54 by juligonz         ###   ########.fr       */
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
