##
## EPITECH PROJECT, 2019
## bootstap_runner
## File description:
## Makefile
##

CC = gcc

SRC = 	src/main.c	\
		src/event/handle_event.c	\
		src/game_objects/game_object.c	\
		src/map/parallax.c	\
		src/scenes/scene.c	\
		src/player/player.c	\
		src/frames/frames.c	\
		src/player/jump.c	\
		src/map/map.c	\
		src/map/player_ground.c	\
		src/physics/physics.c	\
		src/joystick/joystick.c	\
		src/menu/main_menu.c	\
		src/menu/buttons.c	\
		src/menu/main_menu_button_fonctions.c	\
		src/loop/loop.c

OBJ = $(SRC:.c=.o)

NAME = my_runner

CFLAGS = $(LIB) $(HEADER) -g3

LIB = -L./lib -lmy_graph -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

HEADER = -I./include

all : $(NAME)

$(NAME) : make_lib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

make_lib :
	make -C ./lib/my_graph

clean :
	rm -f $(wildcard src/*/*.o)
	rm -f src/*.o
	rm -f vgcore.*
	rm -f lib/my_graph/*.o

fclean : clean
	rm -f $(NAME)
	rm -f lib/libmy_graph.a

re : fclean all