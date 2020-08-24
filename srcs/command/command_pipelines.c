/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:37:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/24 13:53:27 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lst_del_string(void *to_free)
{
	free(to_free);	
}

t_command	*pop_pipeline_from_tokens(t_list *tokens)
{
	t_list		*args;
	t_command	*result;
	t_token		*tok;

	args = NULL;
	result = NULL;
	while (tokens)
	{
		tok = tokens->content;
		if (tok->type == Token_end || (tok->type == Token_operator && !ft_strcmp(tok->str, "|")))
			break;
		ft_lstadd_back(&args, ft_lstnew(ft_strdup(tok->str)));
		tokens = tokens->next;
	}
	result = malloc_command(args);
	if (tok->type == Token_operator && !ft_strcmp(tok->str, "|"))
		result->pipe = pop_pipeline_from_tokens(tokens->next);
	ft_lstclear(&args, lst_del_string);
	return (result);
}


t_list		*get_pipelines(char * input)
{
	t_list		*result;
	t_list		*tokens;

	tokens = tokenize(input);
	result = NULL;

		ft_lstadd_back(&result,
			ft_lstnew(pop_pipeline_from_tokens(tokens)));

	check_commands(result);

	ft_lstclear(&tokens, lst_del_token);

	
	return (result);
}

