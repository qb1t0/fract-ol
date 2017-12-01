#include "includes/fractol.h"




/*
** Setting colors(RGB) for each pixel in 4 bytes of f->im(char *)
*/

void	frctl_im_draw(t_mlx *f, int x, int y, int c)
{
    f->im[x + y] = (char) (c);
    f->im[x + y + 1] = (char) (c >> 8);
    f->im[x + y + 2] = (char)(c >> 16);
}

/*
** frctl_handle_error() handles fractol errors
** switch (type) :
**      0 : print usage
**      1 : function call failed (on fd == 2)
*/

void    frctl_handle_error(int type)
{
    if (!type)
    {
        ft_printf("Usage: ./fractol <fractol name>\n\fAs <fractol name> "
                          "u r available 2 use following agruments :"
                          "\n\t-[mandelbrot];\n\t-[julia];\n\t-[burnship].\n");
    }
    exit(0);
}


void    frctl_set_default(t_mlx *m)
{
    m->sl = 0;
    m->bpp = 0;
    m->zoom = 0.69;
    m->iters = 128;
    m->ymove = 0;
    m->f[0].ysize = 400;
    m->f[0].xsize = 400;
    m->f[1].ysize = 400;
    m->f[1].xsize = 800;
    m->f[2].ysize = 800;
    m->f[2].xsize = 400;
    m->f[3].xsize = 800;
    m->f[3].ysize = 800;
    m->c = 0xF0F0F0;
    m->xmove = m->type == -1 ? (float) -0.5 : 0;
}

/*
** Function frctl_create_new() creates new window
**  with fractal type image inside of it:
**  switch (type) :
**        1 : mandelbrot;
**        2 : julia;
**        3 : burship;
**  ToDo: Add more fractals here.
*/

void    frctl_create_new(t_mlx *m)
{
    printf("%d\n", m->type);
    if (m->type < 0)
    {
        frctl_set_default(m);
        m->type *= -1;
    }
    if (m->type == 1)
        frctl_draw_mandelbrot(m);
    else if (m->type == 2)
        frctl_draw_julia(m);
    else if (m->type == 3)
        frctl_draw_ship(m);
}

/*
** Function frctl_create_window() define default mlx variables
**  + Creates new mlx window;
**  + Starts hooks(button && mouse);
**  + Starts mlx_loop();
*/

void    frctl_create_window(int type)
{
    t_mlx m;

    m.mlx = mlx_init();
    m.new = 0;
    m.mus = 0;
    m.type = (short)type;
    m.win = mlx_new_window(m.mlx, WIDTH + 250, HEIGHT, "fract'ol, ysalata");
    frctl_create_new(&m);
    mlx_mouse_hook(m.win, frctl_onmouse, &m);
    mlx_hook(m.win, 2, 5, frctl_onbutton, &m);
    mlx_loop(m.mlx);
}

/* Guys, no reason 2 read it, here is all simple as fuck*/

int main(int ac, char **av)
{
    if (ac != 2 || !av[1])
        frctl_handle_error(0);
    if (!ft_strcmp(av[1], "mandelbrot"))
        frctl_create_window(-1);
    else if (!ft_strcmp(av[1], "julia"))
        frctl_create_window(-2);
    else if (!ft_strcmp(av[1], "burnship"))
        frctl_create_window(-3);
    else
        frctl_handle_error(0);
}