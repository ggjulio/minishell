/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:38 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/21 13:44:42 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

# define TOKEN_OPERATOR "<>|"
# define TOKEN_SEPARATOR "'\""
# define TOKEN_SPACE " \f\n\r\t\v"
# define TOKEN_VARIABLE "$"
# define TOKEN_ESCAPE "\\"
# define TOKEN_END ";"

typedef enum	e_token_type
{
	None,
	Token_literal,
	Token_operator,
	Token_separator,
	Token_space,
	Token_variable,
	Token_escape,
	Token_end
}				t_token_type;

typedef struct	s_token
{
	char			*str;
	t_token_type	type;
}				t_token;

/*
**	tokenizer.c
*/
t_list			*tokenize(char *input);

/*
**	tokenizer.c
*/
t_token_type	get_token_type(char c);

/*
**	token.c
*/
t_token			create_token(char *str, t_token_type type);
t_token			*malloc_token(char *str, t_token_type type);
void			destroy_token(t_token to_destroy);
void			free_token(t_token *to_free);
void			lst_del_token(void *to_free);

/*
**	token_util.c
*/
t_token			*merge_tokens(t_token *t1, t_token *t2, t_token_type type);
void			print_lst_tokens(t_list *lst);
void			print_token(void *token);

#endif