/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:40 by hwinston          #+#    #+#             */
/*   Updated: 2020/09/11 18:16:52 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_error(const char *arg)
{
	ft_printf("%s: ", g_sh.name);
	ft_printf("unset: ");
	ft_printf("`%s': ", arg);
	ft_printf("not a valid identifier\n");
}

static int	is_valid_identifier(const char *arg)
{
	int i;

	if (arg[0] == '\0' || ft_isdigit(arg[0]))
		return (0);
	i = 0;
	while (arg[i])
	{
		if (ft_in_charset(arg[i], NOT_VALID_CHARS_IN_VAR))
			return (0);
		i++;
	}
	return (1);
}

int			unset(const char **args)
{
	int	i;
	int ret;

	i = 1;
	ret = STATUS_SUCCESS;
	while (args[i])
	{
		if (is_valid_identifier(args[i]))
			remove_environment_variable((char *)args[i]);
		else
		{
			unset_error(args[i]);
			ret = STATUS_FAILURE;
		}
		i++;
	}
	return (ret);
}
