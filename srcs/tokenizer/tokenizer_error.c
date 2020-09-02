/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:19:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/02 20:48:11 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_error(char c)
{
	if (!has_syntax_error(c))
		ft_printf("%s: syntax error near unexpected token `%c'\n",
			g_sh.name, c);
}

int		has_syntax_error(char c)
{
	static char has_error = 0;
	char		tmp;

	tmp = has_error;
	if (c == -1)
		has_error = 0;
	else if (tmp == 0)
		has_error = c;
	return (tmp);
}
