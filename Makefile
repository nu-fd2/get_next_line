NAME = get_next_line.a

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

OBJ = {SRC:.c=.o}

all: ${OBJ}
        ar rcs ${NAME} ${OBJ}

%.o: %.c libft.h
        ${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}

f: fclean all clean
		cc ${CFLAGS} main.c ${NAME}
		./a.out

re: fclean all

.PHONY: all clean fclean re