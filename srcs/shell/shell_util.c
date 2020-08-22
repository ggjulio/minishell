/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/22 13:52:58 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// int spawn (char* program, char** arg_list, char **envp)
// {
// 	pid_t	child_pid;
//
// 	child_pid = fork ();
// 	if (child_pid != 0)
// 	{
// 		wait
// 		waitpid(child_pid,)
//     	return child_pid;
// 	}
// 	else {
//      /* Exécute PROGRAM en le recherchant dans le path. */
//     	execve (program, arg_list, envp);
//      /* On ne sort de la fonction execvp uniquement si une erreur survient. */
//     	ft_printf("une erreur est survenue au sein de execvp\n");
//     	// ft_dprintf(STDERR_FILENO, "une erreur est survenue au sein de execvp\n");
// 	}
// 	return (-1);
// }

// char	**lst_token_to_array(void)
// {
// 	char		**result;
// 	// char 		*ret;
// 	t_token 	*token;
// 	t_list 		*iterator;
// 	int			i;
//
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
	// print_env_list();
	
	(void)tokens;
	
	char *param[3];
	param[0] = ft_strdup("echocc");
	param[1] = ft_strdup("Hello");
	param[2] = 0;
	
	// char *prog = "echo";
	// spawn ("/usr/bin/echo", param, g_sh.env);

	
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
		// print_environment();
		execute_commands(tokens);
		ft_lstclear(&tokens, lst_del_token);
		free(input);
	}
}
