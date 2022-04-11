# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 12:04:57 by xbeheydt          #+#    #+#              #
#    Updated: 2022/04/07 09:03:16 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all tests

NAME		= run-tests
SRCS		= Account.cpp tests.cpp
OBJS		= ${SRCS:.cpp=.o}
SHELL		:= /bin/bash

CC			= c++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -I.

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

$(NAME): ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} -o $@

%.o: %.cpp
	$(CC) ${CFLAGS} -c $< -o $@

clean:
	$(RM) ${OBJS}
	$(RM) '\<'

fclean: clean
	$(RM) ${NAME}
	
tests: all
	diff <(./$(NAME) | awk -F' ' '{print $$2}') <(cat 19920104_091532.log | awk -F' ' '{print $$2}')\
		&& $(PRINTOK) || $(PRINTKO)
