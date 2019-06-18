NAME = fdf

SRCDIR	= ./srcs/

SRC = draw.c \
	  main.c \
	  images.c \
	  keyboard.c \
	  map.c \
	  mouse.c \
	  reader.c

OBJECTS = $(SRC:.c=.o)

INC = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

MLX =  minilibx_macos/libmlx.a

.PHONY: all
all: $(NAME)

$(NAME):
	@make -C libft
	@make -C minilibx_macos
	@echo "\033[32mmaking fdf...\033[0m"
	@$(CC) $(CFLAGS) -c $(addprefix $(SRCDIR),$(SRC)) -I $(INC) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(MLX) $(FRAMEWORK)

.PHONY: clean
clean:
	@echo  "\033[33mcleaning...\033[0m"
	@/bin/rm -f $(OBJECTS)
	@make -C libft clean
	@make -C minilibx_macos clean

.PHONY: fclean
fclean: clean
		rm -rf $(NAME)
		make -C libft fclean
.PHONY: re
re: clean all
