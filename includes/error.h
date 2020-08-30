/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:41:28 by hwinston          #+#    #+#             */
/*   Updated: 2020/08/30 12:10:15 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void    error(char *cmd, const char *arg);
void    bad_command(char *cmd);
int     permission_error(char *command, int option);

#endif
