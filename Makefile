CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT_DIR = ./libft
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_FLAGS = -L $(FT_PRINTF_DIR) -lftprintf

INCLUDES = -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR)

SRCS = main.c free_functions.c helpers.c stack.c validators.c swap.c rotate.c reverse_rotate.c push.c \
		manual_sort.c ranking.c turk_helpers.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	-rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	-rm -f $(NAME)

re: clean fclean all
