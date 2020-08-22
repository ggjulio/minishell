/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:06:20 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/23 00:28:32 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_printf_format(va_list args, t_manager *p)
{
	const char		*conv = "cspdiuxXnfgeo%";
	const t_handler	jmp_table[14] = {conv_c,
									conv_s,
									conv_p,
									conv_d,
									conv_i,
									conv_u,
									conv_x_lowcase,
									conv_x_upcase,
									conv_n,
									conv_f,
									conv_g,
									conv_e,
									conv_o,
									conv_mod};
	int				i;

	i = -1;
	while (conv[++i])
		if (conv[i] == p->specifier)
		{
			jmp_table[i](args, p);
			break ;
		}
}
