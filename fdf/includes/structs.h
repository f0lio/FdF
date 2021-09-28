
#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_point;

typedef struct		s_node
{
	void			*data;
	struct s_node	*next;
}					t_node;

typedef struct		s_file
{
	int				fd;
	int				lines_count;
	t_node			*lines;
	char			**map;

}					t_file;

typedef struct		s_win
{
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	int				*img_d;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
}					t_win;

typedef struct		s_matrix
{
	int				rows;
	int				cols;
	int				**data;
}					t_matrix;

typedef struct		s_env
{
	t_win			win;
	t_file			file;
	t_matrix		matrix;
	float			horizontal_shift;
	float			vertical_shift;
	int				zoom;
	double			angle;
	int				argc;
	const char		**argv;
}					t_env;

#endif
