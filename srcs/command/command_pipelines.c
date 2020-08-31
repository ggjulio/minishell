/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pipelines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:37:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/31 16:31:23 by juligonz         ###   ########.fr       */
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
	t_list		*redirections;
	t_command	*result;
	t_token		*tok;

	args = NULL;
	result = NULL;
	redirections = NULL;
	while (tokens)
	{
		tok = tokens->content;
		if (tok->type == Token_op_pipe)
			break ;
		if (tok->type == Token_literal)
			ft_lstadd_back(&args, ft_lstnew(ft_strdup(tok->str)));
		else if (tok->type == Token_op_dgreat || tok->type == Token_op_great
			|| tok->type == Token_op_less)
			ft_lstadd_back(&redirections, ft_lstnew(malloc_redirection(tok->str,
					get_redirection_type_from_token_type(tok->type))));
		tokens = tokens->next;
	}
	result = malloc_command(args, redirections);
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
