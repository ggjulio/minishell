/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:52:47 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/29 22:55:32 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	concatenate_variables(t_list **tokens)
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
		if (actual->type == Token_variable && next->type == Token_literal)
		{
			iterator->content = merge_tokens(actual, next, actual->type);
			ft_lstdelone(ft_lstpop_elem(tokens, iterator->next), NULL);
		}
		else
			iterator = iterator->next;
	}
}

void	expand_variables(t_list **begin_tokens)
{
	t_list		*iterator;
	t_token		*actual;
	const char	*var_value;
	char		*tmp;

	tmp = NULL;
	iterator = *begin_tokens;
	while (iterator)
	{
		actual = iterator->content;
		if (actual->type == Token_variable)
		{
			if (!is_between_simple_quote(*begin_tokens, iterator))
			{
				if (!ft_strcmp(actual->str, "$"))
					;
				else if (!ft_strncmp("$?", actual->str, 2))
				{
					ft_asprintf(&tmp, "%d%s", g_sh.status, actual->str + 2);
					free(actual->str);
					actual->str = tmp;
				}
				else
				{
					var_value = get_environment_variable_value(actual->str);
					free(actual->str);
					actual->str = ft_strdup(var_value ? var_value : "");
				}
			}
			actual->type = Token_literal;
		}
		iterator = iterator->next;
	}
}
