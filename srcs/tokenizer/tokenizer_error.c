/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:19:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/02 19:47:09 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_syntax_error(char c)
{
	ft_dprintf(1, "%s: syntax error near unexpected token `%c'\n",
		g_sh.name, c);
	has_syntax_error(c);
}

int		has_syntax_error(char c)
{
	static char has_error = 0;
	char		tmp;

	tmp = has_error;
	has_error = c;
	return (tmp);
}
