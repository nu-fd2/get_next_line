# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:24:47 by oel-mado          #+#    #+#              #
#    Updated: 2024/12/08 19:07:17 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

OBJ = ${SRC:.c=.o}

all: ${OBJ}
		ar rcs ${NAME} ${OBJ}

%.o: %.c get_next_line.h
		${CC} ${CFLAGS} -c $< -o $@

f: fclean all clean
		cc ${CFLAGS} main.c ${NAME} -o out
		@echo "-------------------------------------"
		./out | cat -e
		@echo "-------------------------------------"
		@rm out ${OBJ} ${NAME}

clean:
		rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
