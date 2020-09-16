/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:19:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/16 21:19:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_error(char *op)
{
	g_sh.status = STATUS_FAILURE_PARSER;
	if (has_syntax_error(1))
		return ;
	ft_dprintf(STDERR_FILENO,
		"%s: syntax error near unexpected token `%s'\n", g_sh.name, op);
}

int		has_syntax_error(int raise_error)
{
	static char has_error = 0;
	char		tmp;

	tmp = has_error;
	if (raise_error == -1)
		has_error = 0;
	else if (tmp == 0)
		has_error = raise_error;
	return (tmp);
}
