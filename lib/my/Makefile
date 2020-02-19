##
## EPITECH PROJECT, 2019
## Pushswap
## File description:
## Libmy Makefile
##

CC 		= 	gcc

SRC		=	my_clean_str.c \
			my_count_char.c \
			my_count_until_sep.c \
			my_getnbr.c  \
			my_free_2d_array.c \
			my_int_to_strnum.c \
			my_intlen.c \
			my_is_alpha.c \
			my_is_alpha_upper.c \
			my_is_num.c \
			my_putchar.c \
			my_puterr.c \
			my_putstr.c \
			my_revstr.c \
			my_str_isalphanum.c \
			my_str_isnum.c \
			my_str_to_word_array.c \
			my_strarr_dup.c \
			my_strcmp.c \
			my_strdup.c \
			my_strdupcat.c \
			my_strlen.c  \
			my_strncmp.c \
			my_strnum_to_int.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

DBFLAGS	=	-g -g3 -ggdb

HEADER	=	my.h

NAME	=	libmy.a

all:		$(OBJ)
			ar rc $(NAME) $(OBJ)
			cp $(NAME) ../
			cp $(HEADER) ../../include

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f ../../include/$(HEADER)

re:			fclean all

.phony:		re fclean clean
