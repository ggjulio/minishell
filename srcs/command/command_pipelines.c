/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pipelines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:37:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/30 20:43:12 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			lst_del_string(void *to_free)
{
	free(to_free);
}

static t_command	*convert_tokens_to_command(t_list *tokens)
{
	t_list		*args;
	t_command	*result;
	t_token		*tok;

	args = NULL;
	result = NULL;
	while (tokens)
	{
		tok = tokens->content;
		if (tok->type == Token_op_pipe)
			break ;
		if (tok->type == Token_literal)
			ft_lstadd_back(&args, ft_lstnew(ft_strdup(tok->str)));
		else if (tok->type == Token_op_dgreat)
			;
		tokens = tokens->next;
	}
	result = malloc_command(args);
	if (tok->type == Token_op_pipe)
		result->pipe = convert_tokens_to_command(tokens->next);
	ft_lstclear(&args, lst_del_string);
	return (result);
}

t_command			*get_pipeline(char *input)
{
	t_command	*result;
	t_list		*tokens;

	tokens = tokenize(input);
	result = convert_tokens_to_command(tokens);
	ft_lstclear(&tokens, lst_del_token);
	if (!is_valid_pipeline(result))
	{
		free_command(result);
		return (NULL);
	}
	return (result);
}
