/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_util_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:27:16 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/25 17:27:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_del_command(void *to_free)
{
	free_command(to_free);
}