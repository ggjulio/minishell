/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 19:38:45 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int spawn (char* program, char** arg_list, char **envp)
{
	pid_t	child_pid;

	child_pid = fork ();
	if (child_pid != 0)
	{
    	return child_pid;
	}
	else {
     /* Exécute PROGRAM en le recherchant dans le path. */
    	execve (program, arg_list, envp);
     /* On ne sort de la fonction execvp uniquement si une erreur survient. */
    	ft_printf("une erreur est survenue au sein de execvp\n");
    	// ft_dprintf(STDERR_FILENO, "une erreur est survenue au sein de execvp\n");
	}
	return (-1);
}

char	**lst_token_to_array(t_list *tokens)
{
	char	**result;
	t_token	*token;
	int		i;

	if (!(result = malloc((ft_lstsize(tokens) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (tokens)
	{
		token = tokens->content;
		result[i++] = token->str;
		tokens = tokens->next;
	}
	result[i] = 0;
	return (result);
}

char	*get_exec_path(char *exec_name)
{
	size_t			i;
	char			**paths;
    DIR				*dir;
    struct dirent	*dp;

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

void	execute_commands(char **args)
{
	spawn (get_exec_path(args[0]), args, (char **)g_sh.env);
}

void	run_shell(void)
{
	char	*input;
	t_list	*tokens;
	char	**args;

	input = NULL;
	while (42)
	{
		ft_printf("%s$ ", g_sh.name);
		get_next_line(STDIN_FILENO, &input);
		tokens = tokenize(input);
		// print_lst_tokens(tokens);
		args = lst_token_to_array(tokens);
		// int i = 0;
		// while (args[i])
		// 	ft_printf("%s\n", args[i++]);
		// ft_printf(">> %s\n", get_exec_path(((t_token *)(tokens->content))->str));
		execute_commands(args);
		ft_lstclear(&tokens, lst_del_token);
		free(args);
		free(input);
	}
}
