#include "includes/fractol.h"

/*
** Function frctl_create_menu_fr() writes fractal menu
**  + open new window fractal bonus here.
**  + open Mandelbrot || Julia || Burning ship fractal.
**  + open fractal in new window.
*/

void    frctl_create_menu_fr(t_mlx *m)
{
    if (m->mus)
        mlx_string_put(m->mlx, m->win, 990, 291, 0x32CD32, "+");
    else
        mlx_string_put(m->mlx, m->win, 990, 291, 0xB22222, "-");
    mlx_string_put(m->mlx, m->win, 810, 340, 0xFFFFFF, UNDERSCORE);
    mlx_string_put(m->mlx, m->win, 845, 365, 0xFFFFFF, "Fractal's menu");
    mlx_string_put(m->mlx, m->win, 810, 380, 0xFFFFFF, UNDERSCORE);
    mlx_string_put(m->mlx, m->win, 845, 410, 0xB22222, "- Burning ship");
    mlx_string_put(m->mlx, m->win, 845, 440, 0x6495ED, "- Mandelbrot");
    mlx_string_put(m->mlx, m->win, 845, 470, 0x32CD32, "- Julia");
    mlx_string_put(m->mlx, m->win, 810, 500, 0xFFFFFF, NEWWIND);
    if (m->new)
        mlx_string_put(m->mlx, m->win, 1020, 501, 0x32CD32, "+");
    else
        mlx_string_put(m->mlx, m->win, 1020, 501, 0xB22222, "-");
    if (m->type == 2)
    {
        mlx_string_put(m->mlx, m->win, 835, 540, 0xFFFFFF, JULIA);
        mlx_string_put(m->mlx, m->win, 815, 560, 0xFFFFFF, MWHEEL);
    }
}

/*
** Function frctl_create_menu() write settings menu
**  + zoom
**  + color
**  + move guide
**  + music play/pause
*/

void    frctl_create_menu_cs(t_mlx *m)
{
    char *s;

    mlx_string_put(m->mlx, m->win, 810, 0, 0xFFFFFF, UNDERSCORE);
    mlx_string_put(m->mlx, m->win, 840, 25, 0xFFFFFF, "Control Settings");
    mlx_string_put(m->mlx, m->win, 810, 40, 0xFFFFFF, UNDERSCORE);
    mlx_string_put(m->mlx, m->win, 820, 70, 0xFFFFFF, "+ | - zoom: x");
    s = ft_itoa((int)m->zoom);
    mlx_string_put(m->mlx, m->win, 950, 70, 0xFFFFFF, s);
    free(s);
    mlx_string_put(m->mlx, m->win, 820, 100, 0xFFFFFF, "+ | - color:");
    s = ft_itoa(m->c);
    mlx_string_put(m->mlx, m->win, 950, 100, 0xFFFFFF, s);
    free(s);
    mlx_string_put(m->mlx, m->win, 820, 130, 0xFFFFFF, "+ | - iterations:");
    s = ft_itoa(m->iters);
    mlx_string_put(m->mlx, m->win, 1000, 130, 0xFFFFFF, ft_itoa(m->iters));
    free(s);
    mlx_string_put(m->mlx, m->win, 810, 160, 0xFFFFFF, ZOOMIN);
    mlx_string_put(m->mlx, m->win, 810, 190, 0xFFFFFF, ZOOMOUT);
    mlx_string_put(m->mlx, m->win, 810, 220, 0xFFFFFF, MOVEY);
    mlx_string_put(m->mlx, m->win, 810, 250, 0xFFFFFF, MOVEX);
    mlx_string_put(m->mlx, m->win, 830, 290, 0xFFFFFF, "Music playing: [ ]");
    frctl_create_menu_fr(m);
}