/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:19:45 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/18 14:07:56 by juligonz         ###   ########.fr       */
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

/*
** Libraries
*/
# include "libft.h"

/*
**	Minishell
*/
# include "shell.h"
# include "tokenizer.h"

/*
**	Builtins
*/
# include "echo.h"

extern t_shell g_sh;

#endif
