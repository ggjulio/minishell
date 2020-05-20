/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:44:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 17:15:55 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_f(va_list args, t_manager *p)
{
	long double n;

	if (p->f.l_uppercase)
		n = va_arg(args, long double);
	else
		n = va_arg(args, double);
	if (is_valid_float(n, p))
		put_f(n, p);
}
