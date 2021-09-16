
#ifndef STRUCTS_H
# define STRUCTS_H

typedef char		t_bool;

typedef struct		s_env
{
	int				argc;
	char			**argv;
	char			**map;
	int				map_fd;
}					t_env;

#endif
