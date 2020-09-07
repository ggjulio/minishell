/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_split_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:09:07 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/07 19:00:42 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				concatenate_commands(t_list **tokens)
{
	t_list	*iterator;
	t_token	*actual;
	t_token	*next;

	iterator = *tokens;
	if (iterator == NULL)
		return ;
	while (iterator && iterator->next)
	{
		actual = iterator->content;
		next = iterator->next->content;
		if (next->type != Token_end)
		{
			iterator->content = merge_tokens(actual, next, actual->type);
			ft_lstdelone(ft_lstpop_elem(tokens, iterator->next), NULL);
		}
		else
			iterator = iterator->next;
	}
}


char	**split_input(char *input)
{
	t_list	*pipelines;
	char	**result;

	pipelines = assign_token_type_to_each_char(input);
	do_escape(&pipelines);
	manage_quotes(&pipelines);
	// concatenate_literals(&pipelines);
	print_lst_tokens(pipelines);
	concatenate_commands(&pipelines);
	ft_printf("################\n");
	print_lst_tokens(pipelines);
	// if (has_syntax_error(-1))
	// {
		// ft_lstclear(&pipelines, lst_del_token);
		// return (NULL);
	// }
	result = lst_token_to_string_array(pipelines);
	ft_printf("################\n");
	int i = 0;
	while (result[i])
		ft_printf("  %s\n", result[i++]);
	return (result);
}
