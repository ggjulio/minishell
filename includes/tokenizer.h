/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:38 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/20 16:49:36 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

# define TOKEN_OPERATOR "<>"
# define TOKEN_SEPARATOR "'\""
# define TOKEN_SPACE " \f\n\r\t\v"
# define TOKEN_END ";"
# define TOKEN_ESCAPE "\\"

enum	e_token_type
{
	None,
	Token_literal,
	Token_operator,
	Token_separator,
	Token_space,
	Token_escape,
	Token_end,
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
void			lst_del_token(void *to_free);

#endif
