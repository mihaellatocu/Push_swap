NAME = push_swap
SOURCES = push_swap.c methods.c utils.c ft_strings.c sort.c methods_b.c clean.c

OBJECTS = $(SOURCES:.c=.o)

CC=cc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
