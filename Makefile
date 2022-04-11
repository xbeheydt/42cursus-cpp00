# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:30:27 by xbeheydt          #+#    #+#              #
#    Updated: 2022/04/06 12:55:04 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all re tests ex00 ex01 ex02

EXOS	= ex00 ex01 ex02

all: ${EXOS}

${EXOS}:
	$(MAKE) -C $@ ${RECIPE}

tests: RECIPE = tests
tests: ${EXOS}

clean: RECIPE = clean
clean: ${EXOS}

fclean: RECIPE = fclean
fclean: ${EXOS}
