//
// Created by Yaroslav Salata on 11/26/17.
//
#include "includes/fractol.h"

int     fractol_onbutton(int button, t_map *m)
{
    mlx_do_sync(m->mlx);
    mlx_clear_window(m->mlx, m->win);
    if (button == 124)
        m->xmove += 10;
    else if (button == 123)
        m->xmove -= 10;
    else if (button == 126)
        m->ymove -= 10;
    else if (button == 125)
        m->ymove += 10;
    else if (button == 69)
        m->zoom *= 1.1;
    else if (button == 78)
        m->zoom /= 1.1;
    frctl_count_mandl(m, -1, -1, 0);
    mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
    mlx_destroy_image(m->mlx, m->img);
}