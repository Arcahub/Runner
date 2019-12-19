##
## EPITECH PROJECT, 2019
## bootstap_runner
## File description:
## Makefile
##

CC = gcc

SRC = 	$(shell find ./src/ -iname "*.c")

OBJ = $(SRC:.c=.o)

RMD_FILES = $(OBJ) vgcore.* lib/my_graph/*.o lib/my/*.o

NAME = my_runner

CFLAGS = $(LDFLAGS) $(HEADER)

LDFLAGS = -L./lib -lmy_graph -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

HEADER = -I./include

all : $(NAME)

debug:
	$(CFLAGS += -g3)
	@printf "[DEBUG]\n"
	@make -s fclean $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) $< -c  -o $@
	@printf "[compiled] % 50s\n" $(notdir $<) | tr ' ' '.'

$(NAME) : start_compil make_lib $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@printf "[END compil]\n"

start_compil:
	@printf "[START compil]\n"

make_lib :
	@printf "[START libs compil]\n"
	@make -sC ./lib/my_graph
	@printf "[compiled] % 50s\n" "libmy_graph.a" | tr ' ' '.'
	@make -sC ./lib/my
	@printf "[compiled] % 50s\n" "libmy.a" | tr ' ' '.'
	@printf "[END libs compil]\n"

clean :
	@printf "[START clean]\n"
	@rm -f $(RMD_FILES)
	@printf "[removed] % 50s\n" $(notdir $(OBJ)) | tr ' ' '.'
	@printf "[END clean]\n"

fclean : clean
	@printf "[START fclean]\n"
	@rm -f $(NAME) lib/libmy_graph.a lib/libmy.a
	@printf "[removed] % 50s\n" $(notdir $(NAME)) | tr ' ' '.'
	@printf "[END fclean]\n"

re : fclean all