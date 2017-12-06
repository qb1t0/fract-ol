#include "includes/fractol.h"

void    frctl_play_music(int *a)
{
    *a = *a ? 0 : 1;

}


int     frctl_onbutton(int button, t_mlx *m)
{
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

void    frctl_mouse_move(t_mlx *m, int b, int x, int y)
{
    double x1;
    double x2;
    double y1;
    double y2;


    if (b == 4)
    {
        x1 = ((double)x - HLFW) / (HLFW * m->zoom);
        x2 = ((double)x - HLFW) / (HLFW * m->zoom * 1.1);
        y1 = ((double)y - HLFH) / (HLFH * m->zoom);
        y2 = ((double)y - HLFH) / (HLFH * m->zoom * 1.1);
        m->zoom *= 1.06;
        m->xmove -= (x2 - x1);
        m->ymove -= (y2 - y1);
    }
    else if (b == 5)
    {
        x1 = ((double)x - HLFW) / (HLFW * m->zoom);
        x2 = ((double)x - HLFW) / (HLFW * m->zoom / 1.1);
        y1 = ((double)y - HLFH) / (HLFH * m->zoom);
        y2 = ((double)y - HLFH) / (HLFH * m->zoom / 1.1);
        m->zoom /= 1.06;
        m->xmove -= (x2 - x1);
        m->ymove -= (y2 - y1);
    }
    else if (b == 6)
      m->julia += 0.01;
    else if (b == 7)
      m->julia -= 0.01;
}

void    frctl_mouse_input(t_mlx *m, int x, int y, int *buf)
{
    if (x > 982 && x < 1006 && y > 297 && y < 311)
        frctl_play_music(&m->mus);
        //m->mus = m->mus ? 0 : 1;
    if (x > 847 && y > 417)
    {
        if (x < 984 && y < 431)
            *buf = -3;
        else if (x < 964 && y > 445 && y < 460)
            *buf = -1;
        else if (x < 916 && y > 475 && y < 490)
            *buf = -2;
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
    int buf;

    mlx_clear_window(m->mlx, m->win);
    buf = m->type;
    printf("%d %d %d\n", b, x, y);
    if (b == 1)
        frctl_mouse_input(m, x, y, &buf);
    else if ((b > 3 && b < 8))
        frctl_mouse_move(m, b,x ,y);
    if (buf < 0 && m->new)
    {
        frctl_create_new(m);
        frctl_create_window(buf);
    }
    else if (buf < 0)
    {
        m->type = (short)buf;
        frctl_create_new(m);
    }
    else
        frctl_create_new(m);
}