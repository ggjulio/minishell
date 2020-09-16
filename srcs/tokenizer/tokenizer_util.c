/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:32:18 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/16 20:57:37 by juligonz         ###   ########.fr       */
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
	if (ft_in_charset(c, TOKEN_SEPARATOR))
		return (Token_separator);
	if (ft_in_charset(c, TOKEN_END))
		return (Token_end);
	return (Token_literal);
}

char			**lst_string_to_string_array(t_list *lst_strings)
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

char			**lst_token_to_string_array(t_list *lst_token)
{
	char	**result;
	int		i;

	if (!(result = malloc((ft_lstsize(lst_token) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (lst_token)
	{
		result[i++] = ft_strdup(((t_token *)(lst_token->content))->str);
		lst_token = lst_token->next;
	}
	result[i] = 0;
	return (result);
}

void			remove_tokens_type(t_list **tokens, t_token_type type_to_remove)
{
	t_token *token_ref;

	token_ref = malloc_token("", type_to_remove);
	ft_lst_remove_if(tokens, token_ref, cmp_token_type, lst_del_token);
	free_token(token_ref);
}
