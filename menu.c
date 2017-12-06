#include "includes/fractol.h"

/*
** Function frctl_create_menu_fr() writes fractal menu
**  + open new window fractal bonus here.
**  + open Mandelbrot || Julia || Burning ship fractal.
**  + open fractal in new window.
*/

void    frctl_create_menu_fr(t_mlx *m) {
    mlx_string_put(m->mlx, m->win, 810, 340, 0xFFFFFF, "______________________");
    mlx_string_put(m->mlx, m->win, 845, 365, 0xFFFFFF, "Fractal's menu");
    mlx_string_put(m->mlx, m->win, 810, 380, 0xFFFFFF, "______________________");
    mlx_string_put(m->mlx, m->win, 845, 410, 0xB22222, "- Burning ship");
    mlx_string_put(m->mlx, m->win, 845, 440, 0x6495ED, "- Mandelbrot");
    mlx_string_put(m->mlx, m->win, 845, 470, 0x32CD32, "- Julia");
    mlx_string_put(m->mlx, m->win, 810, 500, 0xFFFFFF, "Open in new window: [ ]");
    if (m->new)
        mlx_string_put(m->mlx, m->win, 1020, 501, 0x32CD32, "+");
    else
        mlx_string_put(m->mlx, m->win, 1020, 501, 0xB22222, "-");
    if (m->type == 2) {
        mlx_string_put(m->mlx, m->win, 835, 540, 0xFFFFFF, "Modify Julia set:");
        mlx_string_put(m->mlx, m->win, 815, 560, 0xFFFFFF, "mwheelleft/mwheelright");

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
    mlx_string_put(m->mlx, m->win, 810, 0, 0xFFFFFF, "______________________");
    mlx_string_put(m->mlx, m->win, 840, 25, 0xFFFFFF, "Control Settings");
    mlx_string_put(m->mlx, m->win, 810, 40, 0xFFFFFF, "______________________");
    mlx_string_put(m->mlx, m->win, 820, 70, 0xFFFFFF, "+ | - zoom: x");
    mlx_string_put(m->mlx, m->win, 950, 70, 0xFFFFFF, ft_itoa((int)m->zoom));
    mlx_string_put(m->mlx, m->win, 820, 100, 0xFFFFFF, "+ | - color:");
    mlx_string_put(m->mlx, m->win, 950, 100, 0xFFFFFF, ft_itoa(m->c));
    mlx_string_put(m->mlx, m->win, 820, 130, 0xFFFFFF, "+ | - iterations:");
    mlx_string_put(m->mlx, m->win, 1000, 130, 0xFFFFFF, ft_itoa(m->iters));
    mlx_string_put(m->mlx, m->win, 810, 160, 0xFFFFFF, "zoom in:     mwheelup");
    mlx_string_put(m->mlx, m->win, 810, 190, 0xFFFFFF, "zoom out:    mwheeldown");
    mlx_string_put(m->mlx, m->win, 810, 220, 0xFFFFFF, "move Y-axis: up/down");
    mlx_string_put(m->mlx, m->win, 810, 250, 0xFFFFFF, "move X-axis: left/right");
    mlx_string_put(m->mlx, m->win, 830, 290, 0xFFFFFF, "Music playing: [ ]");
    if (m->mus)
        mlx_string_put(m->mlx, m->win, 990, 291, 0x32CD32, "+");
    else
        mlx_string_put(m->mlx, m->win, 990, 291, 0xB22222, "-");
    frctl_create_menu_fr(m);
}