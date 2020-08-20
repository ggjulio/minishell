/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:13:38 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/20 15:30:35 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token		create_token(char *str, enum e_token_type type)
{
	t_token result;

	result.str = ft_strdup(str);
	result.type = type;
	return (result);
}

t_token		*malloc_token(char *str, enum e_token_type type)
{
	t_token *result;

	if ((result = malloc(sizeof(t_token))) == NULL)
		return (NULL);
	*result = create_token(str, type);
	return (result);
}

void		destroy_token(t_token to_destroy)
{
	free(to_destroy.str);
}

void		free_token(t_token *to_free)
{
	destroy_token(*to_free);
	free(to_free);
}

void	lst_del_token(void *to_free)
{
	free_token(to_free);
}