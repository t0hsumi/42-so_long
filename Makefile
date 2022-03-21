NAME = so_long

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
DEBUG		= -g -fsanitize=address
INCLUDES	= -I./includes -I./minilibx-linux -I./libft
LIB			= -L ./minilibx-linux -lXext -lX11 -lm

minilibx = ./minilibx-linux/libmlx_Linux.a
libft = ./libft/libft.a

SRCS = ./srcs/main.c ./srcs/check.c ./srcs/get_next_line.c \
	   ./srcs/get_next_line_utils.c ./srcs/error.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS) $(DEBUG) $(INCLUDES) $(LIB)

$(minilibx):
	make -C ./minilibx-linux

$(libft):
	make -C ./libft

$(NAME): $(OBJS) $(minilibx) $(libft)
	$(CC) $(OBJS) $(minilibx) $(libft) $(CFLAGS) $(DEBUG) $(INCLUDES) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ./minilibx-linux
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
