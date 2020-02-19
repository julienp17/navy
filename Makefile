##
## EPITECH PROJECT, 2020
## PSU_navy_2019
## File description:
## Makefile
##

CC			=	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
MAIN_F		=	main.c
OBJ_M		=	$(MAIN:.c=.o)

SRC			=	$(addprefix $(SRC_D), $(SRC_F))
OBJ			=	$(SRC:.c=.o)
SRC_D		=	src/
SRC_F		=

SRC_UT		=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT		=	$(SRC_UT:.c=.o)
SRC_UT_D	=	tests/
SRC_UT_F	=

INC			=	-I./include

CFLAGS		=	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS) $(DBFLAGS)

LDFLAGS		=	-L./lib -lmy

LDFLAGS_UT  =	-lcriterion --coverage

DBFLAGS		=	-g -g3 -ggdb

NAME		=	navy

NAME_UT		=	unit_tests

all: $(NAME)

$(NAME): makelib $(OBJ) $(OBJ_M)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(CFLAGS) $(DBFLAGS)

tests_run: makelib clean $(SRC) $(OBJ_UT)
	$(CC) -o $(NAME_UT) $(SRC) $(OBJ_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT)

makelib:
	make -C ./lib/my all

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	make -C ./lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my fclean

re: fclean all