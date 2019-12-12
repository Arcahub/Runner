##
## EPITECH PROJECT, 2019
## bootstap_runner
## File description:
## Makefile
##

CC = gcc

SRC = 	src/main.c	\
		src/handle_event.c	\
		src/game_object.c	\
		src/parallax.c	\
		src/scene.c	\
		src/player.c	\
		src/frames.c	\
		src/jump.c

OBJ = $(SRC:.c=.o)

NAME = my_runner

CFLAGS = $(LIB) $(HEADER) -g3

LIB = -L./lib -lmy_graph -lcsfml-graphics -lcsfml-window -lcsfml-system

HEADER = -I./include

all : $(NAME)

$(NAME) : make_lib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

make_lib :
	make -C ./lib/my_graph

clean :
	rm -f src/*.o
	rm -f lib/my_graph/*.o

fclean : clean
	rm -f $(NAME)
	rm -f lib/libmy_graph.a

re : fclean all