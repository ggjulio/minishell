/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/21 16:55:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int spawn (char* program, char** arg_list, char **envp)
{
	pid_t	child_pid;

	child_pid = fork ();
	if (child_pid != 0)
    	return child_pid;
	else {
     /* Exécute PROGRAM en le recherchant dans le path. */
    	execve (program, arg_list, envp);
     /* On ne sort de la fonction execvp uniquement si une erreur survient. */
    	ft_printf("une erreur est survenue au sein de execvp\n");
    	ft_dprintf(STDERR_FILENO, "une erreur est survenue au sein de execvp\n");
	}
	return (-1);
}

char	**lst_env_to_array(void)
{
	char		**result;
	// char 		*ret;
	t_env_var 	*env_var;
	t_list 		*iterator;
	int			i;

	iterator = g_sh.env.lst_var;
	if (!(result = malloc((ft_lstsize(iterator) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (iterator)
	{
		env_var = iterator->content;
		// ft_asprintf(&ret, "%s=%s", env_var->name, env_var->value);
		// result[i] = ret;
		char *tmp = ft_strdupcat(env_var->name, "=");
		result[i] = ft_strdupcat(tmp, env_var->value);
		free(tmp);
		iterator = iterator->next;
		i++;
	}
	result[i] = 0;
	return (result);
}

// char	**lst_token_to_array(void)
// {
// 	char		**result;
// 	// char 		*ret;
// 	t_token 	*token;
// 	t_list 		*iterator;
// 	int			i;

// 	iterator = g_sh.env.lst_var;
// 	if (!(result = malloc((ft_lstsize(iterator) + 1) * sizeof(char *))))
// 		return (NULL);
// 	i = 0;
// 	while (iterator)
// 	{
// 		token = iterator->content;
// 		char *tmp = ft_strdupcat(token->, "=");
// 		result[i] = ft_strdupcat(tmp, token->value);
// 		free(tmp);
// 		iterator = iterator->next;
// 		i++;
// 	}
// 	result[i] = 0;
// 	return (result);
// }

void	execute_commands(t_list *tokens)
{
	char **arr = lst_env_to_array();
	int i = 0;
	
	(void)tokens;
	(void)arr;
	(void)i;
	
	// spawn (, , lst_env_to_array());


	// ft_printf("##################################\n");
	// ft_printf("############# HERE ###############\n");
	// ft_printf("##################################\n");
	// while(arr[i])
	// 	ft_printf("%s\n", arr[i++]);
}

void	run_shell(void)
{
	char	*input;
	t_list	*tokens;

	input = NULL;
	while (42)
	{
		ft_printf("%s$ ", g_sh.name);
		get_next_line(STDIN_FILENO, &input);
		tokens = tokenize(input);
		// print_env();
		execute_commands(tokens);
		ft_lstclear(&tokens, lst_del_token);
		free(input);
	}
}
