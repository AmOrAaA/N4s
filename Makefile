##
## Makefile for make in /home/broscas/CPE_2016_n4s/n4s_package
## 
## Made by Ryan Granet
## Login   <ryan.granet@epitech.eu>
## 
## Started on  Wed May  3 14:05:07 2017 Ryan Granet
## Last update Tue May 30 13:16:26 2017 Ryan Granet
##

CFLAGS	+=	-I./include -L./lib/my/ -lmy -L./lib/ -Wextra -Wall -pedantic

CC = gcc

NAME = ai

SRC =	src/get_next_line.c	\
	src/wordtab.c		\
	src/print.c		\
	src/str_to_float.c	\
	src/my_ai.c		\
	src/all_str_to_word.c	\
	src/track_cleared.c	\
	src/parse_str.c		\
	src/all_check.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
