# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 12:04:57 by xbeheydt          #+#    #+#              #
#    Updated: 2022/04/06 12:55:08 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all tests

NAME		= megaphone
SRCS		= megaphone.cpp

CC			= c++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

RM			= rm -rf

define OK
	\n\033[32m[OK]\033[0m\n\n
endef
export OK
PRINTOK 	:= printf $$OK
define NO
	\n\033[31m[KO]\033[0m\n\n
endef
export KO
PRINTKO 	:= printf $$KO

all: $(NAME)

$(NAME):
	$(CC) ${CFLAGS} ${SRCS} -o $@

clean:
	$(RM) ${NAME}

fclean: clean
	$(RM) test.out

tests: all
	./$(NAME) "shhhhh... I think the students are asleep..." > test.out;\
		echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." | diff test.out - \
		&& $(PRINTOK) || $(PRINTKO);
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off." > test.out;\
		echo "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." | diff test.out - \
		&& $(PRINTOK) || $(PRINTKO);
	./$(NAME) > test.out;\
		echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *" | diff test.out - \
		&& $(PRINTOK) || $(PRINTKO);