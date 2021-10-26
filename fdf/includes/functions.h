
#ifndef _FUNCTIONS_H
# define _FUNCTIONS_H

void		init_env(t_env *env, int argc, const char **argv);
void		init_file(t_file *file);
void		init_win(t_win *win);
void		clear_window(t_env *env);
void		setup(t_env *env);
void		start_engine(t_env *env);
void		normalize_alt(t_env *env);
void		update(t_env *env);
void		update_window(t_env *env);
void		render(t_env *env);
void		isometric_projection(
	int *x, int *y, float z, double angle);
void		set_event_hooks(t_env *env);
int			key_hook(int key, t_env *env);
int			mouse_hook(int btn, int x, int y, t_env *env);
void		open_map(t_env *env);
void		read_map(t_env *env);
int			read_line(int fd, char **line);
void		*mem_move(void *dst, const void *src, size_t len);
int			has_return(char *str);
char		*get_save(char *save);
char		*get_line(char *str);

void		parse_map(t_env *env);
t_point		*parse_map_line(t_env *env, t_string *str, int *cols);

int			parse_color(char *buf, int *i);
char		*get_hex_from_line(char *line);
int			has_color(char *line);

void		error_exit(t_env *env, char *msg);
void		clean_exit(t_env *env, int exit_code);

size_t		str_len(const char *str);
void		put_char(char c);
void		put_str(char *str);
char		*sub_str(char *line, unsigned start, unsigned end);
char		*str_join(char const *s1, char const *s2);
char		*str_dup(const char *s1);

t_string	*init_string(int size);
t_string	*make_string(char *buff, int len);
void		destroy_string(t_string **s);
int			str_to_int(const char *str);
int			str_hex_to_int(const char *str);
int			nbr_len(long i);
int			count_by_delim(char *str, char c);
int			skip_char(char *str, char c);
t_node		*new_node(void);
void		push_back(t_node **list, void *data);
void		destroy_list(t_node **list, void(*func)(void **));
void		pxl(t_env *env, t_point *p);
void		set_window(t_env *env);
int			close_window(t_env *env);
void		project_line(t_env *env,
					int x, int y, int x1, int y1);
void		set_point(t_point *p, int x, int y, int zoom);
void		reset_point(t_point *p);
void		set_projection(t_env *env, int *x, int *y);
float		get_max(float a, float b);
float		get_min(float a, float b);
void		controllers(t_env *env, int key);
void		show_info(t_env *env);
void		safe_free(void **ptr);
char		**str_split(char const *s, char c, int *items_count);
void		*mem_alloc(int size);
void		free_splited_items(char **items, int size);
#endif
