/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/21 13:48:52 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_commands(t_list *tokens)
{
	(void)tokens;
}

void	run_shell(void)
{
	char	*input;
	t_list	*tokens;

	input = NULL;
	while (42)
	{
		ft_printf("%s$ ", g_sh.name);
		get_next_line(STDIN_FILENO, &input);
		tokens = tokenize(input);
		execute_commands(tokens);
		ft_lstclear(&tokens, lst_del_token);
		free(input);
	}
}
