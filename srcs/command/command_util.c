/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:45:43 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/24 01:09:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_exec_path(char *exec_name)
{
	size_t			i;
	char			**paths;
    DIR				*dir;
    struct dirent	*dp;

	if (!ft_strncmp("./",exec_name, 2) || !ft_strncmp("/",exec_name, 1))
		return (ft_strdup(exec_name));
	paths = malloc_environment_path();
	i = -1;
	while (paths[++i])
	{
		dir = opendir(paths[i]);
		if (dir == NULL)
			continue;
		while ((dp = readdir(dir)) != NULL)
			if (!ft_strcmp(exec_name, dp->d_name))
			{
				char *tmp = ft_strdupcat(paths[i], "/");
				char *result = ft_strdupcat(tmp, exec_name);
				free(tmp);
				return (result);
			}
   		closedir(dir);
	}	
	free_environment_path(paths);
	return (NULL);
}

void		print_command(t_command *to_print)
{
	int i;

	i = 0;
	while (to_print->args[i])
		ft_printf("%s ", to_print->args[i++]);		
	if (to_print->pipe != NULL)
	{
		ft_printf(" | ");
		print_command(to_print->pipe);
		
	}
	ft_printf("\n");
}
