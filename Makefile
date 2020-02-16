##
## Makefile for Makefile in /home/zaczyk_a/rendu/Piscine_C_evalexpr
## 
## Made by Anoine Zaczyk
## Login   <zaczyk_a@epitech.net>
## 
## Started on  Thu Oct 22 15:08:45 2015 Anoine Zaczyk
## Last update Sun Feb 21 01:11:55 2016 Antoine Zaczyk
##

NAME=		allum1

SRC=		src/main.c \
		src/map.c \
		src/my_print.c \
		src/basic_function.c \
		src/str_to_wordtab.c \
		src/user_turn.c \
		src/check.c \
		src/get_next_line.c \
		src/ia_turn.c 

CFLAGS=		-W -Wextra -Wall -Werror -g\
		-I.

all:		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(CFLAGS) -Iinclude

clean:
		rm -f *~
		rm -f *#

fclean:		clean
		rm -f $(NAME)

re:		fclean all
