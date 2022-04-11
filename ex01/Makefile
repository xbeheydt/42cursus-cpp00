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

NAME		= phonebook
SRCS		= PhoneBook.cpp Contact.cpp cin_handlers.cpp main.cpp
#SRCS		= main.cpp
OBJS		= ${SRCS:.cpp=.o}

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

fclean: clean
	$(RM) ${NAME}
	
tests: all
	./$(NAME)
