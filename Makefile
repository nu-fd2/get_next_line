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

m1:
		cc -Wall -Wextra -Werror main.c
		./a.out | cat -e

m2:
		cc -Wall -Wextra -Werror -g main.c ${SRC}
		valgrind --leak-check=full --show-leak-kinds=all -s ./a.out | cat -e

m2n:
		cc -Wall -Wextra -Werror main.c ${SRC}
		./a.out | cat -e

f: fclean all clean
		cc ${CFLAGS} main.c ${NAME}
		./a.out

re: fclean all

.PHONY: all clean fclean re