/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pipelines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:37:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/27 18:43:04 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lst_del_string(void *to_free)
{
	free(to_free);
}

t_command	*pop_pipeline_from_tokens(t_list *tokens, t_list **iterator)
{
	t_list		*args;
	t_command	*result;
	t_token		*tok;

	args = NULL;
	result = NULL;
	while (tokens)
	{
		tok = tokens->content;
		if (tok->type == Token_end || tok->type == Token_op_pipe)
			break ;
		ft_lstadd_back(&args, ft_lstnew(ft_strdup(tok->str)));
		tokens = tokens->next;
	}
	result = malloc_command(args);
	if (tok->type == Token_op_pipe)
		result->pipe = pop_pipeline_from_tokens(tokens->next, iterator);
	else
		*iterator = tokens;
	ft_lstclear(&args, lst_del_string);
	return (result);
}

t_list		*get_pipelines(char *input)
{
	t_list		*result;
	t_list		*tokens;
	t_list		*iterator;
	t_token		*tok;

	result = NULL;
	tokens = tokenize(input);
	iterator = tokens;
	while (iterator)
	{
		tok = iterator->content;
		if (tok->type != Token_end)
			ft_lstadd_back(&result, ft_lstnew(pop_pipeline_from_tokens(iterator, &iterator)));
		else
			iterator = iterator->next;
	}
	// t_list *res_to_print = result;
	// while (res_to_print)
	// {
	// 	print_command(res_to_print->content);
	// 	res_to_print = res_to_print->next;
	// }
	
	check_commands(result);
	ft_lstclear(&tokens, lst_del_token);
	return (result);
}
