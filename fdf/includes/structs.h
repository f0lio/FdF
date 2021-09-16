
#ifndef STRUCTS_H
# define STRUCTS_H

typedef char		t_bool;

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

typedef struct		s_env
{
	int				argc;
	const char		**argv;
	t_file			file;
}					t_env;

#endif
