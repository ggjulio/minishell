/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:31:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/23 17:34:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int spawn (char* bin_path, char** arg_list, char **envp)
{
	pid_t	child_pid;
	int		status;

	child_pid = fork ();
	if (child_pid == -1)
		return (-1);
	if (child_pid != 0)
	{
		waitpid(child_pid, &status, 0);
    	return child_pid;
	}
	else {
    	execve (bin_path, arg_list, envp);
    	ft_printf("une erreur est survenue au sein de execvp\n");
	}
	return (0);
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

void	execute_commands(t_command **commands)
{
	// spawn (get_exec_path(args[0]), args, (char **)g_sh.env);
	(void)commands;
}



t_command	*pop_pipeline_from_tokens(t_list **tokens)
{
	t_command	*result;
	t_list		*iterator;
	t_token		*tok;

	iterator = *tokens;
	result = NULL;
	while (iterator)
	{
		tok = iterator->content;
		if (tok->type == Token_end)
			return (result);
		if (tok->type == Token_operator && !ft_strcmp(tok->type, "|"))
		{
			ft_lstdelone(ft_lstpop_elem(tokens, iterator), lst_del_token);
			result->pipe = pop_command_from_tokens(tokens);
		}
		
		iterator = iterator->next;
	}
	return (result);
}


t_list	*get_commands(char * input)
{
	t_list		*result;
	t_list		*tokens;
	t_command 	*pipeline;

	tokens = tokenize(input);
	if ((pipeline = pop_pipeline_from_tokens(&tokens)) != NULL)
		ft_lstadd_back(&result, ft_lstnew(pipeline));
	else
			

	ft_lstclear(&tokens, lst_del_token);
	



	// char	**args;
	// args = lst_token_to_array(tokens);
	// free(args);
}









void	run_shell(void)
{
	char	*input;

	input = NULL;
	while (42)
	{
		ft_printf("%s%s%s$%s ", "\e[92m", g_sh.name, "\e[91m", "\e[0m");
		get_next_line(STDIN_FILENO, &input);
		execute_commands(get_commands(input));
		free(input);
	}
}
