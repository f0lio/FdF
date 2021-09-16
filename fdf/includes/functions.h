
#ifndef _FUNCTIONS_H
# define _FUNCTIONS_H

void    init_env(t_env *env, int argc, char **argv);
void    setup(t_env *env);


void        open_map(t_env *env);
void        read_map(t_env *env);
int         read_line(int fd, char **line);

void        error_exit(t_env *env, char *msg);
void        clean_exit(t_env *env, int exit_code);

size_t      str_len(const char *str);
void        put_char(char c);
void        put_str(char *str);

#endif