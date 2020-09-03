/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:19:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/03 17:27:52 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_error(char *op)
{
	if (has_syntax_error(1))
		return ;
	ft_printf("%s: syntax error near unexpected token `%s'\n", g_sh.name, op);
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
