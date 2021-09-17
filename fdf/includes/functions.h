
#ifndef _FUNCTIONS_H
# define _FUNCTIONS_H

void        init_env(t_env *env, int argc, const char **argv);
void        init_file(t_file *file);
void        init_win(t_win *win);

static void        setup(t_env *env);
static void        render(t_env *env);
static int         update(int key, t_env *env);

void        open_map(t_env *env);
void        read_map(t_env *env);
void        parse_map(t_env *env);
int         read_line(int fd, char **line);

void        error_exit(t_env *env, char *msg);
void        clean_exit(t_env *env, int exit_code);

size_t      str_len(const char *str);
void        put_char(char c);
void        put_str(char *str);
char	*str_join(char const *s1, char const *s2);


t_node      *new_node(void);
void        push_back(t_node **list, void *data);

void	pxl(t_env *env, t_point *p);
void	set_window(t_env *env);
int		close_window(t_env *env);

char	*str_dup(const char *s1);

#endif