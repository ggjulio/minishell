/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:41:28 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/16 14:52:02 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int     echo(char **args);
int     cd(char *arg);
int     pwd();
int     export(char *arg);
int     env();
int     unset(char *name);
int     exit_builtin();

#endif
