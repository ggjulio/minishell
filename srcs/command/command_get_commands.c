/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:37:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/23 23:51:45 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lst_del_string(void *to_free)
{
	free(to_free);	
}

static char	**lst_string_to_array(t_list *lst_strings)
{
	char	**result;
	int		i;

	if (!(result = malloc((ft_lstsize(lst_strings) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (lst_strings)
	{
		result[i++] = ft_strdup(lst_strings->content);
		lst_strings = lst_strings->next;
	}
	result[i] = 0;
	return (result);
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
	result = malloc_command(lst_string_to_array(args));
	if (tok->type == Token_operator && !ft_strcmp(tok->str, "|"))
		result->pipe = pop_pipeline_from_tokens(tokens->next);
	ft_lstclear(&args, lst_del_string);
	return (result);
}


t_list		*get_commands(char * input)
{
	t_list		*result;
	t_list		*tokens;

	tokens = tokenize(input);
	result = NULL;

		ft_lstadd_back(&result,
			ft_lstnew(pop_pipeline_from_tokens(tokens)));


	ft_lstclear(&tokens, lst_del_token);
	
	return (result);
}

