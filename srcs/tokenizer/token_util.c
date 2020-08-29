/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:25:58 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/29 22:45:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token		*merge_tokens(t_token *t1, t_token *t2, t_token_type type)
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

void		print_lst_tokens(t_list *lst)
{
	t_token		*token;
	const char	str[10][15] = {"None", "literal", "operator", "op_pipe",
			"separator", "space", "variable", "escape", "end"};

	while (lst)
	{
		token = lst->content;
		ft_printf("%10s : \"%s\"\n", str[token->type], token->str);
		lst = lst->next;
	}
}

void		print_token(void *token)
{
	const char	str[10][15] = {"None", "literal", "operator", "op_pipe",
		"separator", "space", "variable", "escape", "end"};

	ft_printf("             str  : \"%s\"\n", ((t_token *)token)->str);
	ft_printf("             type : %s\n", str[((t_token *)token)->type]);
}

int			cmp_token_type(t_token *t1, t_token *t2)
{
	return (t1->type != t2->type);
}