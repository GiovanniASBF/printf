NAME = libftprintf.a

LIBFT = libft/libft.a

SRC = format_converter.c \
	ft_printf.c \
	input_handler.c \
	printer.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft
#rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(eval LIBFT_OBJ := $(shell ar -t $(LIBFT)))
	ar crs $(NAME) $(OBJ) $(addprefix libft/, $(LIBFT_OBJ))

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

# New rules for testing
TEST_SRC = test.c
TEST_NAME = a.out
TEST_OBJ = $(TEST_SRC:.c=.o)

test: $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -L. -lftprintf -o $(TEST_NAME)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

test_run: test
	./$(TEST_NAME)

test_clean:
	rm -f $(TEST_OBJ) $(TEST_NAME)

.PHONY: all bonus clean fclean re test test_run test_clean

# the -I flag add a directory to the list of places where 
# the compiler should search for the header files.
# ar -t command list all objects (.o) 
# inside the static library file $(LIBFT).