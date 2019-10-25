NAME = wolf3d
SRCS		=	main.c \
				reader.c \
				texture.c \
				raycasting.c \
				parsing.c \
				hooks_release.c \
				create_walls.c \
				create_floor.c \
				init_for_recast.c \
				out_error.c \
				key_hooks.c \
				vector.c \
				get_next_line.c 

SRCO		= $(SRCS:.c=.o)
FLAGS		= -Wall -Wextra -Werror
HEADER      = -I /usr/local/include/ -I includes/
MLX			= -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit -lm -lpthread
LIBS		= libft/libft.a 
LIB_DIR = libft/
DIR = obj/
SRC = $(SRCS)
OBJ = $(addprefix $(DIR),$(SRCS:.c=.o))

all: $(NAME)


$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@cc $(OBJ) -o $(NAME) $(HEADER) $(MLX) -L $(LIB_DIR) -lft
	@echo "     *****     wolf3d complied     *****     "


obj/%.o: %.c
	@mkdir -p $(DIR)
	@gcc -c $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
