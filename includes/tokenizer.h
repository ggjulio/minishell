/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:38 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/19 18:53:35 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

# define TOKEN_OPERATOR "&|<>"
# define TOKEN_SEPARATOR "'\""

enum	e_token_type
{
	Token_literal,
	Token_operator,
	Token_separator,
};

typedef struct	s_token
{
	char				*str;
	enum e_token_type	type;
}				t_token;

/*
**	tokenizer.c
*/
t_list			*tokenize(char *input);

/*
**	token.c
*/
t_token			create_token(char *str, enum e_token_type type);
t_token			*malloc_token(char *str, enum e_token_type type);
void			destroy_token(t_token to_destroy);
void			free_token(t_token *to_free);

#endif
