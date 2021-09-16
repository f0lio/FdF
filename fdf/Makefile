
.PHONEY: all clean fclean re

NAME	=	fdf

HEADERS = ./includes
PARSER	= read_line.c read_map.c
ENGINE	= 
UTILS	= exit_handlers.c write_utils.c str_utils.c

SRC		=	src/fdf.c\
			$(PARSER:%.c=./src/parser/%.c)\
			$(UTILS:%.c=./src/utils/%.c)

CC		=	gcc
FLAGS	=	-Werror -Wextra -Wall
_MLX_	=	-I minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) -I$(HEADERS) $(_MLX_) -o $(NAME)   -g #$(FLAGS)

clean:
	@rm -rf *.o

fclean: clean
	@-rm -f $(NAME)

re: fclean all