NAME = so_long

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
DEBUG		= -g -fsanitize=address
INCLUDES	= -I./includes -I./minilibx-linux
LIB			= -L ./minilibx-linux -lXext -lX11 -lm

minilibx = ./minilibx-linux/libmlx_Linux.a

SRCS = ./srcs/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS) $(DEBUG) $(INCLUDES) $(LIB)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(minilibx) $(CFLAGS) $(DEBUG) $(INCLUDES) $(LIB)

clean:
	rm -f $(OBJS)
	make clean -C ./minilibx-linux

fclean: clean
	rm -f $(NAME)
	make fclean -C ./minilibx-linux

re: fclean all

.PHONY: all clean fclean re
