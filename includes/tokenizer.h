/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:06:38 by juligonz          #+#    #+#             */
/*   Updated: 2020/09/19 17:56:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

# define TOKEN_OPERATOR "<>|"
# define TOKEN_QUOTE "'\""
# define TOKEN_SPACE " \t"
# define TOKEN_VARIABLE "$"
# define TOKEN_ESCAPE "\\"
# define TOKEN_SEPARATOR ",[]{}"
# define TOKEN_END ";"

# define DGREAT ">>"
# define GREAT ">"
# define LESS "<"

typedef enum	e_token_type
{
	Token_None,
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
	Token_separator,
	Token_end,
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
t_list			*assign_token_type_to_each_char(char *input);

/*
**	tokenizer_util.c
*/
t_token_type	get_token_type(char c);
char			**lst_string_to_string_array(t_list *lst_strings);
char			**lst_token_to_string_array(t_list *lst_strings);
void			remove_tokens_type(
					t_list **tokens, t_token_type type_to_remove);

/*
**	tokenizer_util_quote.c
*/
int				in_simple_quote(t_list *begin_tokens, t_list *to_find);
int				in_double_quote(t_list *begin_tokens, t_list *to_find);
int				in_quote(t_list *begin_tokens, t_list *to_find);

/*
**	tokenizer_variable.c
*/
void			concatenate_variables(t_list **tokens);
void			expand_variables(t_list **begin_tokens);

/*
**	tokenizer_quote.c
*/
void			manage_quotes(t_list **tokens);
void			manage_empty_quotes(t_list **begin_list);

/*
**	tokenizer_error.c
*/
int				has_syntax_error(int raise_error);
void			syntax_error(char *op);
/*
**	tokenizer_validation.c
*/
void			validation_backslash(t_list *begin_list);
void			validation_pipes(t_list *begin_list);
void			validation_tokens(t_list *begin_list);

/*
**	tokenizer_redirection.c
*/
void			redirection_detect_operator(t_list **begin_tokens);
void			redirection_join_arg(t_list **begin_tokens);

/*
** tokenizer_split_input.c
*/
char			**split_input(char *input);

/*
** tokenizer_split_input_util.c
*/
void			split_do_escape(t_list **begin_tokens);
void			split_manage_quotes(t_list **tokens);

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
