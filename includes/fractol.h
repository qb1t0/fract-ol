#ifndef FRACTOL_LIBRARY_H
# define FRACTOL_LIBRARY_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# import <OpenCL/Opencl.h>
#include <stdio.h>
#include <pthread.h>
# define WIDTH 800
# define HEIGHT 800
# define HLFW 400
# define HLFH 400
# define N 4

/*
**  Struct s_o uses for 1 pixel representation
**  x,y,z : axis coordinates
**     c : 4-bytes color representation (RGBA)
*/

typedef struct	    s_o{
    float		    x;
    float		    y;
    float		    z;
    int			    c;
}				    t_o;

/*
**  Struct s_map uses for collecting data about the drawing picture
**  ToDo: add variables description here
*/

typedef struct	    s_map{
    /* Fractol variables */
    int             c;      //color variable
    int             i;      //crawler
    double          cre;    //current real part of the "c" const(shape for)
    double          cim;    //current imaginary part of the "c" const(shape for)
    double          nre;    //z real part
    double          nim;    //z imaginary part
    double          sre;    //square of real z-parts(z.r * z.r) value
    double          sim;    //square of imaginary z-parts(z.i * z.i) value
    int             xsize;   //I'm using it for 4-thread WIDTH divine
    int             ysize;   //I'm using it for 4-thread WIDTH divine
    double          hzoom;
    double          wzoom;
}				    t_map;

/*
**  Struct s_mlx uses for collecting data from mlx functions
**  ToDo: add variables description here
*/

typedef struct      s_mlx{
    /* Variables needed by the mlx library functions */
    void		    *mlx;
    void		    *win;
    void		    *img;
    char		    *im;
    int			    bpp;
    int             end;
    int             new;
    int             mus;
    int			    sl;
    int             part; // index of 1/4 part of our input data
    /* Fractol variables */
    struct s_map    f[4];

    int             c;      //color variable
    float           zoom;   //zoom value
    float		    xmove;  //move on x axis value
    float		    ymove;  //move on y axis value
    short           iters;  //iteration
    short           type;   //fractal type
}                   t_mlx;

void    frctl_mouse_input(t_mlx *m, int x, int y);
int     frctl_onmouse(int button, int x, int y, t_mlx *m);
int     frctl_onbutton(int button, t_mlx *m);

void    frctl_create_window(int type);
void    frctl_create_new(t_mlx *m);

void	frctl_im_draw(t_mlx *f, int x, int y, int c);
void    frctl_create_menu_cs(t_mlx *m);

void    frctl_draw_julia(t_mlx *m);
void    *frctl_tread_julia(void *arg);
void    *frctl_count_julia(t_mlx *m, t_map f, int x, int y);

void    frctl_draw_ship(t_mlx *m);
void    *frctl_tread_ship(void *arg);
void    *frctl_count_ship(t_mlx *m, t_map f, int x, int y);

void    frctl_draw_mandelbrot(t_mlx *m);
void    *frctl_tread_mandelbrot(void *arg);
void    *frctl_count_mandelbrot(t_mlx *m, t_map f, int x, int y);

#endif