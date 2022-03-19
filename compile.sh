make -C ./minilibx-linux
gcc $1 ./minilibx-linux/libmlx_Linux.a -I ./minilibx-linux -L ./minilibx-linux -lXext -lX11 -lm

