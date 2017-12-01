#include "includes/fractol.h"

int     frctl_onbutton(int button, t_mlx *m)
{
    mlx_do_sync(m->mlx);
    mlx_clear_window(m->mlx, m->win);
    if (button == 124)
        m->xmove -= 0.02 / m->zoom;
    else if (button == 123)
        m->xmove += 0.02 / m->zoom;
    else if (button == 126)
        m->ymove += 0.02/ m->zoom;
    else if (button == 125)
        m->ymove -= 0.02 / m->zoom;
    else if (button == 69)
        m->zoom *= 1.1;
    else if (button == 78)
        m->zoom /= 1.1;
    frctl_create_new(m);
    return (1);
}

void    frctl_mouse_input(t_mlx *m, int x, int y)
{
    if (x > 982 && x < 1006 && y > 297 && y < 311)
        m->mus = m->mus ? 0 : 1;
    if (x > 847 && y > 417)
    {
        if (x < 984 && y < 431)
            m->type = -3;
        else if (x < 964 && y > 445 && y < 460)
            m->type = -1;
        else if (x < 916 && y > 475 && y < 490)
            m->type = -2;
        else if (x > 1018 && x < 1037 && y > 506 && y < 521)
            m->new = m->new ? 0 : 1;
    }
    else if (x > 815 && x < 836)
    {
        y > 73 && y < 91 ? m->zoom *= 1.1 : 0;
        y > 104 && y < 120 ? m->c += 303333 : 0;
        y > 134 && y < 152 ? m->iters += 10 : 0;
    }
    else if (x > 855 && x < 875)
    {
        y > 73 && y < 91 ? m->zoom /= 1.1 : 0;
        y > 104 && y < 120 ? m->c -= 303333 : 0;
        y > 134 && y < 152 ? m->iters -= 10 : 0;
    }
}

int     frctl_onmouse(int b, int x, int y, t_mlx *m)
{
    mlx_do_sync(m->mlx);
    mlx_clear_window(m->mlx, m->win);
    printf("%d %d\n", x, y);
    if (b == 1)
        frctl_mouse_input(m, x, y);
    if (m->type < 0 && m->new)
    {
        m->type *= -1;
        frctl_create_new(m);
        frctl_create_window(m->type * -1);
    }
    else
        frctl_create_new(m);
        //frctl_create_new(m);
}