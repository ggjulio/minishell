/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:52:47 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/11 18:57:39 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		concatenate_variables(t_list **tokens)
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
		if (actual->type == Token_variable && next->type == Token_literal
			&& !ft_in_charset(next->str[0], NOT_VALID_CHARS_IN_VAR))
		{
			iterator->content = merge_tokens(actual, next, actual->type);
			ft_lstdelone(ft_lstpop_elem(tokens, iterator->next), NULL);
		}
		else
			iterator = iterator->next;
	}
}

static void	expand_variables_do_expansion(t_list *iterator)
{
	t_list		*lst_to_insert;
	const char	*var_value;

	var_value = (char *)get_environment_variable_value(
							((t_token *)(iterator->content))->str);
	if (var_value)
	{
		lst_to_insert = assign_token_type_to_each_char((char *)var_value);
		ft_lstinsert_lst_after(iterator, lst_to_insert);
	}
}

static void	expand_variables_expand_status(t_token *actual)
{
	char		*tmp;

	ft_asprintf(&tmp, "%d%s", g_sh.status, actual->str + 2);
	free(actual->str);
	actual->str = tmp;
	actual->type = Token_literal;
}

void		expand_variables(t_list **begin_tokens)
{
	t_list		*iterator;
	t_token		*actual;

	iterator = *begin_tokens;
	while (iterator)
	{
		actual = iterator->content;
		if (actual->type == Token_variable)
		{
			if (!in_simple_quote(*begin_tokens, iterator))
			{
				if (!ft_strcmp(actual->str, "$"))
					actual->type = Token_literal;
				else if (!ft_strncmp("$?", actual->str, 2))
					expand_variables_expand_status(actual);
				else
					expand_variables_do_expansion(iterator);
			}
			else
				actual->type = Token_literal;
		}
		iterator = iterator->next;
	}
}
