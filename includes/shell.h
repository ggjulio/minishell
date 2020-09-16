/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:54:31 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/16 16:31:03 by juligonz         ###   ########.fr       */
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

/*
**  https://www.thegeekstuff.com/2010/10/linux-error-codes/
*/

# define STATUS_SUCCESS				0
# define STATUS_FAILURE 			1
# define STATUS_FAILURE_BUILTIN 	2
# define STATUS_NOT_EXECUTABLE		126
# define STATUS_CMD_NOT_FOUND		127
# define STATUS_EXIT_INVALID_ARGS	128
# define STATUS_CTRL_C				130
# define STATUS_CTRL_BACKSLASH		131

# ifdef DARWIN
#  define STATUS_FAILURE_PARSER		2
# else
#  define STATUS_FAILURE_PARSER		1
# endif

typedef struct		s_shell
{
	char			*name;
	t_environment	env;
	char			*cwd;
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
void				run_shell_commands(char **commands);
void				run_shell(void);
void				prompt_name(void);

/*
**	shell_signal.c
*/
void				sigint_handler(int sig);
void				sigquit_handler(int sig);
int					set_signal(void);

#endif
