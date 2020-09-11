/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_split_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:09:07 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/11 22:49:33 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		concatenate_commands_keep_spaces(t_list **tokens)
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
		if (actual->type != Token_end
			&& actual->type != Token_space
			&& next->type != Token_end
			&& next->type != Token_space)
		{
			iterator->content = merge_tokens(actual, next, actual->type);
			ft_lstdelone(ft_lstpop_elem(tokens, iterator->next), NULL);
		}
		else
			iterator = iterator->next;
	}
}

static void		concatenate_commands(t_list **tokens)
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
		if (actual->type != Token_end && next->type != Token_end)
		{
			iterator->content = merge_tokens(actual, next, actual->type);
			ft_lstdelone(ft_lstpop_elem(tokens, iterator->next), NULL);
		}
		else
			iterator = iterator->next;
	}
}

static void		validation_end(t_list *begin_list)
{
	t_list	*iterator;
	t_token	*actual_tok;
	int		last_was_end;

	last_was_end = 1;
	iterator = begin_list;
	while (iterator)
	{
		actual_tok = iterator->content;
		if (actual_tok->type == Token_end)
		{
			if (last_was_end)
				return (syntax_error(";"));
			else
				last_was_end = 1;
		}
		else if (actual_tok->type != Token_space)
			last_was_end = 0;
		iterator = iterator->next;
	}
}

char			**split_input(char *input)
{
	char	**result;
	t_list	*pipelines;

	pipelines = assign_token_type_to_each_char(input);
	split_do_escape(&pipelines);
	split_manage_quotes(&pipelines);
	concatenate_commands_keep_spaces(&pipelines);
	validation_end(pipelines);
	if (has_syntax_error(-1))
	{
		ft_lstclear(&pipelines, lst_del_token);
		return (NULL);
	}
	concatenate_commands(&pipelines);
	remove_tokens_type(&pipelines, Token_end);
	result = lst_token_to_string_array(pipelines);
	ft_lstclear(&pipelines, lst_del_token);
	return (result);
}
