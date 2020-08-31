/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:19:45 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/31 15:06:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

/*
** Libraries
*/
# include "libft.h"

/*
**	Minishell
*/
# include "environment.h"
# include "command.h"
# include "shell.h"
# include "tokenizer.h"
# include "error.h"
# include "redirection.h"

/*
**	Builtins
*/
# include "builtins.h"

extern t_shell g_sh;

#endif
