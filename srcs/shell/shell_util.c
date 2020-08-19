/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 22:34:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_shell(void)
{
	char *input;

	input = NULL;
	while (42)
	{
		ft_printf("%s$", g_sh.name);
		get_next_line(STDIN_FILENO, &input);
		ft_printf("%s\n", input);
		tokenize(input);
		free(input);
	}
}
