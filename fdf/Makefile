
.PHONEY: all clean fclean re

NAME	=	fdf

HEADERS = 	./includes -lm
PARSER	= 	read_line.c parse_map.c parse_line.c gnl.c
ENGINE	= 	render.c window.c event_hooks.c show_info.c normalize_alt.c
UTILS	= 	constructors.c exit_handlers.c write_utils.c linked_list.c\
			string.c str_utils.c nbr_utils.c str_split.c

SRC		=	src/fdf.c\
			$(PARSER:%.c=./src/parser/%.c)\
			$(ENGINE:%.c=./src/engine/%.c)\
			$(UTILS:%.c=./src/utils/%.c)

CC		=	gcc
FLAGS	=	-Werror -Wextra -Wall
DBG		=	-g
# _MLX_	=	-I minilibx -lmlx -framework OpenGL -framework AppKit
_MLX_	=	-L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) -I$(HEADERS) $(_MLX_) -o $(NAME) $(DBG) $(FLAGS)

clean:
	@rm -rf *.o

fclean: clean
	@-rm -f $(NAME)

re: fclean all

demo: $(NAME)
	./$(NAME) ../maps/demo.fdf
