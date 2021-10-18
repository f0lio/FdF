
#include "fdf.h"

void show_info(t_env *env)
{
    if (!env->show_info)
    {
        mlx_string_put(
            env->win.mlx_p, env->win.win_p, 15, 20, CYAN, "Show/Hide info: SPACE");
        return ;
    }
    mlx_string_put(
        env->win.mlx_p, env->win.win_p, 15, 20, CYAN, "Rendering:");
    mlx_string_put(
        env->win.mlx_p, env->win.win_p, 30, 35, CYAN, (char*)env->argv[1]);
    mlx_string_put(
        env->win.mlx_p, env->win.win_p, 15, 50, CYAN, "Actions:");
    mlx_string_put(
        env->win.mlx_p, env->win.win_p, 30, 65, CYAN, "ZOOM     : Mouse wheel");
    mlx_string_put(
        env->win.mlx_p, env->win.win_p, 30, 80, CYAN, "MOVE     : Arrows");
    mlx_string_put(
        env->win.mlx_p, env->win.win_p, 30, 95, CYAN, "ANGLE    : W/S");
    mlx_string_put(
        env->win.mlx_p, env->win.win_p, 30, 110, CYAN,"VIEW     : V");
    mlx_string_put(
        env->win.mlx_p, env->win.win_p, 30, 125, CYAN,"ALTITUDE : +/-");
    if (env->clicked)
        mlx_string_put(
            env->win.mlx_p, env->win.win_p, 30, 140, GREEN, "Click to drop");
    else
        mlx_string_put(
            env->win.mlx_p, env->win.win_p, 30, 140, CYAN, "Click to select");
}