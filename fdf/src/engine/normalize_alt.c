#include "fdf.h"

void normalize_alt(t_env *env)
{
    int     x;
    int     y;
    float   amplify;

    if (env->max_z > 100)
        amplify = .8;
    else if (env->max_z > 50)
        amplify = .6;
    else if (env->max_z > 30)
        amplify = .8;
    else if (env->max_z > 20)
        amplify = .7;
    else if (env->max_z >= 10)
        amplify = 2;
    else if (env->max_z > 4)
        amplify = 4;
    else
        return ;
    y = 0;
    while (y < env->matrix.rows)
    {
        x = 0;
        while (x < env->matrix.cols)
        {
            env->matrix.data[y][x].z *= amplify;
            x++;
        }
        y++;
    }    

}