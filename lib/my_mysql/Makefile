##
## EPITECH PROJECT, 2019
## test_database
## File description:
## Makefile
##

SRC	=	src/my_query.c	\
		src/my_mysql.c	\
		src/my_res.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -pedantic $(MYSQLFLAGS) -g3

MYSQLFLAGS = `mysql_config --cflags --libs`

NAME = libmy_mysql.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my_mysql.h ../../include
	mv $(NAME) ../
	@make clean

clean :
	@rm -f src/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all