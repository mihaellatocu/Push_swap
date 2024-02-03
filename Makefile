NAME = push_swap.a
SOURCES = \
		push_swap.c methods.c utils.c

OBJECTS = $(SOURCES:.c=.o)

CC=cc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

exec:
	$(CC) $(SOURCES) push_swap.h

$(NAME): $(OBJECTS)
	ar -r $(NAME) $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
