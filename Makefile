##
## EPITECH PROJECT, 2019
## bootstap_runner
## File description:
## Makefile
##

CC = gcc

SRC = 	src/main.c	\
		src/game_logic/handle_event.c	\
		src/game_logic/score.c	\
		src/game_logic/game.c	\
		src/game_objects/game_object.c	\
		src/game_objects/free_objects.c	\
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

CFLAGS = $(LIB) $(HEADER)

LIB = -L./lib -lmy_graph -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

HEADER = -I./include

all : $(NAME)

$(NAME) : make_lib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

make_lib :
	make -C ./lib/my_graph
	make -C ./lib/my

clean :
	rm -f $(wildcard src/*/*.o)
	rm -f src/*.o
	rm -f vgcore.*
	rm -f lib/my_graph/*.o
	rm -f lib/my/*.o

fclean : clean
	rm -f $(NAME)
	rm -f lib/libmy_graph.a
	rm -f lib/libmy.a

re : fclean all