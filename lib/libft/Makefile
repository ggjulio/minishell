# https://misc.flogisoft.com/bash/tip_colors_and_formatting
_BOLD      =\e[1m
_DIM       =\e[2m
_UNDERLINE =\e[4m
_BLINK     =\e[5m
_REVERSE   =\e[7m
_HIDDEN    =\e[8m

# RESET list
_R          =\e[0m
_RBOLD      =\e[21m
_RDIM       =\e[22m
_RUNDERLINE =\e[24m
_RBLINK     =\e[25m
_RREVERSE   =\e[27m
_RHIDDEN    =\e[28m

# Colors
_RED      =\e[91m
_GREEN    =\e[92m
_YELLOW   =\e[93m
_BLUE     =\e[94m
_MAGENTA  =\e[35m
_CYAN     =\e[96m
_WHITE    =\e[97m

# Inverted, i.e. colored backgrounds
_IRED     =\e[101m
_IGREEN   =\e[102m
_IYELLOW  =\e[103m
_IBLUE    =\e[104m
_IMAGENTA =\e[45m
_ICYAN    =\e[106m
_IWHITE   =\e[107m

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/15 12:07:06 by juligonz          #+#    #+#              #
#    Updated: 2020/02/14 11:53:23 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC_DIR = $(shell find ./srcs -type d)
OBJ_DIR = obj
INC_DIR = includes

SRC = ft_memset.c	ft_bzero.c	ft_memcpy.c	ft_memccpy.c
SRC+= ft_memmove.c ft_memchr.c ft_memcmp.c
SRC+=  ft_strlen.c	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c
SRC+=	ft_isprint.c ft_toupper.c ft_tolower.c	ft_strchr.c
SRC+=	ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c
SRC+=	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

SRC+=	ft_substr.c	ft_strjoin.c ft_strtrim.c ft_split.c
SRC+= ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c
SRC+= ft_putendl_fd.c ft_putnbr_fd.c

SRC+= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c
SRC+=	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c
SRC+=	ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC+= ft_abs.c ft_iscntrl.c	ft_isupper.c ft_isgraph.c
SRC+= ft_isblank.c ft_islower.c	ft_isspace.c ft_isxdigit.c
SRC+= ft_itoa_base.c ft_labs.c ft_llabs.c ft_memdel.c
SRC+= ft_putchar.c ft_putendl.c ft_putnbr_base.c
SRC+= ft_putnbr_base_fd.c ft_putnbr.c ft_putstr.c
SRC+= ft_strcat.c ft_strcmp.c ft_strcpy.c ft_strncat.c
SRC+= ft_strncpy.c ft_strnew.c ft_strdel.c ft_strclr.c
SRC+= ft_striter.c ft_striteri.c ft_strmap.c ft_strequ.c 
SRC+= ft_strnequ.c ft_strstr.c ft_strndup.c ft_print_memory.c

SRC+= get_next_line.c ft_valid_extention.c ft_in_charset.c
SRC+= ft_isnumber.c ft_lstpop_front.c

OBJ     = $(addprefix  $(OBJ_DIR)/,$(SRC:%.c=%.o))
vpath %.c $(SRC_DIR)


CC      = clang
CFLAGS  = -Wall -Wextra -Werror #-g
IFLAGS  =  -I./includes

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# libs:
# 	@make -s -C ft_printf/
# 	@mv ft_printf/libftprintf.a ./$(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^
	@printf "$(_GREEN)Compiled : $(_MAGENTA)$(NAME)$(_R)\n"
	@printf "\nDo $(_CYAN)$(_BOLD)make show$(_R) to debug the Makefile\n\n"

show:
	@printf "$(_MAGENTA)UNAME  :$(_GREEN)  $(shell uname)$(_END)\n"
	@printf "$(_MAGENTA)ARCH   :$(_GREEN)  $(shell uname -p)$(_END)\n\n"
	@printf "$(_CYAN)CC     :$(_RED)  $(CC)$(_END)\n"
	@printf "$(_CYAN)CFLAGS :$(_RED)  $(CFLAGS)$(_END)\n\n"
	@printf "$(_CYAN)IFLAGS :$(_RED)  $(IFLAGS)$(_END)\n\n"
	@printf "$(_CYAN)SRC    :$(_RED)  $(SRC)$(_END)\n"
	@printf "$(_CYAN)OBJ    :$(_RED)  $(OBJ)$(_END)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(_RED)Removed :$(_MAGENTA) $(OBJ_DIR)/$(_MAGENTA)\n"

shit_to_delete:
	@make clean -s -C ft_printf/

fclean: clean
	@rm -fr $(NAME)
	@printf "$(_RED)Removed : $(_MAGENTA)$(NAME)$(_R)\n"


bonus: $(NAME)

re_echo:
	@printf "$(_CYAN)Redoing $(_BOLD)ALLL $(_R)$(_CYAN)$(_DIM)the things$(_R)$(_BOLD)$(_YELLOW)...$(_R)\n\n"

re: re_echo fclean all

.PHONY: all show clean fclean bonus re