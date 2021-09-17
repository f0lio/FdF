
.PHONEY: all clean fclean re

NAME	=	fdf

HEADERS = 	./includes
PARSER	= 	read_line.c read_map.c
ENGINE	= 	init.c window.c render.c draw.c setters.c utils.c
UTILS	= 	constructors.c exit_handlers.c write_utils.c linked_list.c\
			str_utils.c nbr_utils.c

SRC		=	src/fdf.c\
			$(PARSER:%.c=./src/parser/%.c)\
			$(ENGINE:%.c=./src/engine/%.c)\
			$(UTILS:%.c=./src/utils/%.c)

CC		=	gcc
FLAGS	=	-Werror -Wextra -Wall
_MLX_	=	-I minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) -I$(HEADERS) $(_MLX_) -o $(NAME) -fsanitize=address  -g #$(FLAGS)

clean:
	@rm -rf *.o

fclean: clean
	@-rm -f $(NAME)

re: fclean all