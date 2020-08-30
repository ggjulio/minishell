/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:45:43 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/30 12:11:02 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_exec_path(char *exec_name)
{
	size_t			i;
	char			**paths;
	DIR				*dir;
	struct dirent	*dp;
	char			*result;

	if (!ft_strncmp("./", exec_name, 2) || !ft_strncmp("/", exec_name, 1))
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
				ft_asprintf(&result, "%s/%s", paths[i], exec_name);
				closedir(dir);
				free_environment_path(paths);
				return (result);
			}
		closedir(dir);
	}
	free_environment_path(paths);
	return (NULL);
}

void	print_command(t_command *to_print)
{
	int		i;

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

int             is_executable(t_command *command)
{
    struct stat		*stats;

	if (!(stats = malloc(sizeof(struct stat))))
		return (-1);
	if (stat(command->args[0], stats) == -1)
    {
        error(command->args[0], "");
        return (0);
    }
    if (S_ISREG(stats->st_mode) == 0)
    {
        free(stats);
        return (permission_error(command->args[0], 1));
    }
    else if ((stats->st_mode & S_IXUSR) == 0)
    {
        free(stats);
        return (permission_error(command->args[0], 2));
    }
    free(stats);
    return (1);
}