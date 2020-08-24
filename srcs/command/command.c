/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/24 13:53:12 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**lst_token_to_string_array(t_list *lst_strings)
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

t_command	create_command(t_list *p_args)
{
	t_command	result;

	ft_bzero(&result, sizeof(t_command));
	result.args = lst_token_to_string_array(p_args);
	result.bin_path = get_exec_path(result.args[0]);
	result.pipe = NULL;
	return (result);
}

t_command		*malloc_command(t_list *p_args)
{
	t_command	*result;

	if ((result = malloc(sizeof(t_command))) == NULL)
		return (NULL);
	*result = create_command(p_args);
	return (result);
}

void		destroy_command(t_command to_destroy)
{
	free(to_destroy.bin_path);
	(void)to_destroy;
}

void		free_command(t_command *to_free)
{
	destroy_command(*to_free);
	free(to_free);
}
