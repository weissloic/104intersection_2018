##
## EPITECH PROJECT, 2018
## 104pong_2018
## File description:
## The Makefile of the 104intersection project
##

NAME = 104intersection

SRC =	main.c \

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lm

clean:
	rm *.o
fclean:
	rm -f $(NAME)
	make clean

re: fclean all

.phony: all clean fclean $(NAME)
