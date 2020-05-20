
# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/20 12:43:01 by juligonz          #+#    #+#              #
#    Updated: 2020/05/20 12:51:11 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

LIB = ft

SRC_DIR = $(shell find ./srcs -type d)
INC_DIR = includes
OBJ_DIR = obj
LIB_DIR = $(shell find ./lib -type d -maxdepth 1)

SRC = main.c

OBJ = $(addprefix  $(OBJ_DIR)/,$(SRC:%.c=%.o))
vpath %.c $(SRC_DIR)

LFLAGS = $(foreach lib, $(LIB_DIR),-L$(lib))  $(foreach lib, $(LIB),-l$(lib))

CC = clang
CFLAGS  = -Wall -Wextra -Werror -g # -fsanitize=address  -fsanitize=undefined -fstack-protector  
IFLAGS  = -I./lib/libft -I./includes

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(_GREEN)Compiling ...$(_END)"
	@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $@ $^
	@echo "$(_GREEN)Compiled !$(_END)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_GREEN).o removed !$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_GREEN)$(NAME) program removed !$(_END)"

bonus: $(NAME)

show:
	@echo "$(_CYAN)SRC_DIR    :$(_RED)  $(SRC_DIR)$(_END)"
	@echo "$(_CYAN)SRC    :$(_RED)  $(SRC)$(_END)"
	@echo "$(_CYAN)OBJ    :$(_RED)  $(OBJ)$(_END)"
	@echo "$(_CYAN)IFLAGS :$(_RED)  $(IFLAGS)$(_END)"
	@echo "$(_CYAN)LFLAGS :$(_RED)  $(LFLAGS)$(_END)"
	@echo "$(_CYAN)CFLAGS :$(_RED)  $(CFLAGS)$(_END)"

re: fclean all


install: 
	@echo "$(_GREEN)Install libft.a ...$(_END)"
	@make -s -C lib/libft/
	@echo "$(_RED)done ...$(_END)"

fclean-install:
	@echo "$(_GREEN)fclean-install libft.a ...$(_END)"
	@make fclean -s -C lib/libft/


re-install: fclean-install install


.PHONY: clean fclean re all bonus install re-install fclean-install


#******************************************************************************#
#                                  REMINDER                                    #  
#******************************************************************************# \
                                                                                 \
                                                                                 \
Automatic variables :                                                            \
                                                                                 \
$@ : rule name  target.         			                                     \
                                                                                 \
$^ : The names of all the prerequisites, with spaces between them. For           \
prerequisites which are archive members, only the named member is used.          \
                                                                                 \
$< : The name of the first prerequisite. If the target got its recipe from an    \
implicit rule, this will be the first prerequisite added by the implicit rule.   \
                                                                                 \
$? : The names of all the prerequisites that are newer than the target, with     \
spaces between them. For prerequisites which are archive members, only the       \
named member is used.                                                            \
                                                                                 \
                                                                                 \
source :                                                                         \
https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html      \

#******************************************************************************#
#                                  RESSOURCES                                  #  
#******************************************************************************# \
resources :                                                                      \
https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents       \
http://web.mit.edu/gnu/doc/html/make_toc.html#SEC88                              \
https://www3.nd.edu/~zxu2/acms60212-40212/Makefile.pdf                           \
