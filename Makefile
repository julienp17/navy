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
SRC_F		=	usage.c \
				navy.c \
				get_next_line.c \
				game/game_loop.c \
				game/print_grids.c \
				game/get_input.c \
				signals/join_connections.c \
				signals/signals_handler.c \
				signals/send_coord.c \
				signals/wait_transmission.c \
				structures/grid/cell_is_boat.c \
				structures/grid/grid_create.c \
				structures/grid/grid_print.c \
				structures/grid/grid_place_boat.c \
				structures/grid/grid_has_boats.c \
				format_parsing/coord_is_valid.c \
				format_parsing/format_is_valid.c \
				format_parsing/get_grid_from_file.c \

SRC_UT		=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT		=	$(SRC_UT:.c=.o)
SRC_UT_D	=	tests/
SRC_UT_F	=	test_get_next_line.c \
				test_coord_is_valid.c \
				test_check_args.c \
				tests_grid/test_grid_print.c \
				tests_grid/test_grid_has_boats.c \
				tests_format_parsing/test_format_is_valid.c \

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