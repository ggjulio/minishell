/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:54:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/05 16:42:48 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "minishell.h"

/*
** STATUS CODES
** https://tldp.org/LDP/abs/html/exitcodes.html
** https://shapeshed.com/unix-exit-codes/
*/
# define STATUS_SUCCESS				0
# define STATUS_FAILURE 			1
# define STATUS_FAILURE_BUILTIN 	2
# define STATUS_NOT_EXECUTABLE		126
# define STATUS_CMD_NOT_FOUND		127
# define STATUS_EXIT_INVALID_ARGS	128
# define STATUS_CTRL_C				130

typedef struct		s_shell
{
	char			*name;
	t_environment	env;
	char			cwd[PATH_MAX + 1];
	int				status;
	int				running;
}					t_shell;

/*
** shell.c
*/
t_shell				create_shell(const char *name, t_environment envp);
t_shell				*malloc_shell(char *name, t_environment envp);
void				destroy_shell(t_shell to_destroy);
void				free_shell(t_shell *to_free);

/*
** shell_util.c
*/
void				run_shell(void);
void				execute_pipelines(t_list *commands);
void				prompt_name(void);

/*
**	shell_signal.c
*/
void				sigint_handler(int sig);
void				sigquit_handler(int sig);

/*
**	shell_split_input.c
*/
char				**split_input(char const *s, char c);

#endif
