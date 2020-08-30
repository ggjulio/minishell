/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:38 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/30 20:56:50 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

# define TOKEN_OPERATOR "<>|"
# define TOKEN_QUOTE "'\""
# define TOKEN_SPACE " \f\n\r\t\v"
# define TOKEN_VARIABLE "$"
# define TOKEN_ESCAPE "\\"

# define DGREAT ">>"
# define GREAT ">"
# define LESS "<"

typedef enum	e_token_type
{
	None,
	Token_literal,
	Token_operator,
	Token_op_pipe,
	Token_op_great,
	Token_op_dgreat,
	Token_op_less,
	Token_quote,
	Token_space,
	Token_variable,
	Token_escape,
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
**	tokenizer_util.c
*/
t_token_type	get_token_type(char c);
char			**lst_token_to_string_array(t_list *lst_strings);
int				is_between_simple_quote(t_list *begin_tokens, t_list *to_find);
void			remove_spaces(t_list **tokens);

/*
**	tokenizer_variable.c
*/
void			concatenate_variables(t_list **tokens);
void			expand_variables(t_list **begin_tokens);

/*
**	token_util.c
*/
void			redirection_detect_operator(t_list **begin_tokens);
void			redirection_join_arg(t_list **begin_tokens);

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
int				cmp_token_type(t_token *t1, t_token *t2);

#endif
