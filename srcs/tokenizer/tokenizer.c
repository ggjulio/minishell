/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/20 16:48:08 by juligonz         ###   ########.fr       */
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
	if (ft_in_charset(c, TOKEN_END))
		return (Token_end);
	if (ft_in_charset(c, TOKEN_ESCAPE))
		return (Token_escape);
	return (Token_literal);
}

void				print_tokens(t_list *lst)
{
	t_token		*token;
	const char str[7][15] = {"None", "literal", "operator",
			"separator", "space", "escape", "end"};

	while (lst)
	{
		token = lst->content;
		ft_printf("%10s : %s\n", token->str, str[token->type]);
		lst = lst->next;
	}
}

void print_token(void *token)
{
	const char str[7][15] = {"None", "literal", "operator",
		"separator", "space", "escape", "end"};
	
	ft_printf("             str  : \"%s\"\n", ((t_token *)token)->str);
	ft_printf("             type : %s\n", str[((t_token *)token)->type]);
}

t_token		*merge_tokens(t_token *t1, t_token *t2, enum e_token_type type)
{
	t_token	*result;
	char	*str;	

	str = ft_strdupcat(t1->str, t2->str);
	result = malloc_token(str, type);
	free(str);
	free_token(t1);
	free_token(t2);
	return (result);
}

void				concatenate_literals(t_list **tokens)
{
	t_list		*iterator;
	t_token 	*actual;
	t_token 	*next;

	iterator = *tokens;
	if (iterator == NULL)
		return ;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (actual->type == next->type && actual->type == Token_literal)
		{
			iterator->content = merge_tokens(actual, next, actual->type);;
			ft_lstdelone(ft_lstpop_elem(tokens, iterator->next), NULL);
		}
		else
			iterator = iterator->next;
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

	concatenate_literals(&result);
	ft_printf("\nAFTER concatenation\n\n");
	print_tokens(result);
	
	return (result);
}

