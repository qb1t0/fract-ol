#include "includes/fractol.h"
#include <stdio.h>
#include <pthread.h>


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
        ft_printf("Usage: ./fractol <fractol name>\n\f"
                          "As <fractol name> u r available 2 use following agruments :"
                          "\n\t-[menu] (opens fractals menu);\n\t"
                          "-[mandelbrot];\n\t-[julia];\n\t-[burnship].\n");
    }
    exit(0);
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

void    frctl_create_new(int type, char *name)
{
    t_map m;

    m.sl = 0;
    m.bpp = 0;
    m.zoom = 1;
    m.xmove = -0.5;
    m.ymove = 0;
    m.iters = 128;
    m.mlx = mlx_init();
    m.win = mlx_new_window(m.mlx, WIDTH, HEIGHT, name);
    m.c = 0xFFFFFF;
    frctl_count_mandl(&m, -1, -1, 0);

//    m.im[WIDTH/ 2 * m.bpp / 8 + m.sl * HEIGHT/2] = (char)m.c;
//    m.im[WIDTH/ 2 * m.bpp / 8 + m.sl * HEIGHT/2 + 1] = (char)(m.c >> 8);
//    m.im[WIDTH/ 2 * m.bpp / 8 + m.sl * HEIGHT/2 + 2] = (char)(m.c >> 16);
    mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
    mlx_destroy_image(m.mlx, m.img);
    mlx_hook(m.win, 2, 5, fractol_onbutton, &m);
    mlx_loop(m.mlx);
}

/*
** Function frctl_create_menu() creates new window
**  with fractals menu inside of it.
*/

void    frctl_create_menu(void)
{
    //ToDo: write menu window here;
}

int main(int ac, char **av)
{
    if (ac != 2 || !av[1])
        frctl_handle_error(0);
    if (!ft_strcmp(av[1], "menu"))
        frctl_create_menu();
    else if (!ft_strcmp(av[1], "mandelbrot"))
        frctl_create_new(1, av[1]);
    else if (!ft_strcmp(av[1], "julia"))
        frctl_create_new(2, av[1]);
    else if (!ft_strcmp(av[1], "burnship"))
        frctl_create_new(3, av[1]);
    else
        frctl_handle_error(0);
    printf("Hello, World!\n");
}