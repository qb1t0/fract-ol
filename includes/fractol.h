#ifndef FRACTOL_LIBRARY_H
# define FRACTOL_LIBRARY_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# import <OpenCL/Opencl.h>
# include <stdio.h>
# include <pthread.h>
# define UNDERSCORE "______________________"
# define ZOOMIN "zoom in:     mwheelup"
# define ZOOMOUT "zoom out:    mwheeldown"
# define MOVEX "move X-axis: left/right"
# define MOVEY "move Y-axis: up/down"
# define MWHEEL "mwheelleft/mwheelright"
# define JULIA "Modify Julia set:"
# define NEWWIND "Open in new window: [ ]"
# define WIDTH 800
# define HEIGHT 800
# define HLFW 400
# define HLFH 400
# define N 4

/*
**  Struct s_map uses for collecting data about the drawing picture
**  Fractol variables
**  int             c;      //color variable
**  int             i;      //crawler
**  double          cre;    //current real part of the "c" const(shape for)
**  double          cim;    //current imaginary part of the "c" const(shape for)
**  double          nre;    //z real part
**  double          nim;    //z imaginary part
**  double          sre;    //square of real z-parts(z.r * z.r) value
**  double          sim;    //square of imaginary z-parts(z.i * z.i) value
**  int             xsize;  //I'm using it for 4-thread WIDTH divine
**  int             ysize;  //I'm using it for 4-thread WIDTH divine
*/

struct      s_mlx;

typedef struct	    s_map{
    int             c;
    int             i;
    double          cre;
    double          cim;
    double          nre;
    double          nim;
    double          sre;
    double          sim;
    int             xsize;
    int             ysize;
    double          hzoom;
    double          wzoom;
}				    t_map;

/*
**  Struct s_mlx uses for collecting data from mlx functions
**  Variables needed by the mlx library functions
**  void		    *mlx;
**  void		    *win;
**  void		    *img;
**  char		    *im;
**  int			    bpp;
**  int			    sl;
**  Fractol variables:
**  int             part; // index of 1/4 part of our input data
**  double          julia;  //variable for Julia Mandelbrot deformation
**  struct s_map    f[4];   //4 fractal image copies for threads
**  int             c;      //color variable
**  float           zoom;   //zoom value
**  double		    xmove;  //move on x axis value
**  double		    ymove;  //move on y axis value
**  short           iters;  //iteration
**  short           type;   //fractal type
*/

typedef struct      s_mlx{
    void		    *mlx;
    void		    *win;
    void		    *img;
    char		    *im;
    int			    bpp;
    int			    sl;
    int             part;
    int             end;
    int             new;
    int             mus;
    double          julia;
    struct s_map    f[4];
    int             c;
    float           zoom;
    double		    xmove;
    double		    ymove;
    short           iters;
    short           type;
}                   t_mlx;

void    frctl_mouse_input(t_mlx *m, int x, int y, int *buf);
int     frctl_onmouse(int button, int x, int y, t_mlx *m);
int     frctl_onbutton(int button, t_mlx *m);


void    frctl_create_window(int type);
void    frctl_create_new(t_mlx *m);

/*
** Function frctl_im_draw(t_mlx *f, int x, int y, int c);
**  Description:
**  - Put pixel colors in struct s_mlx.im
*/

void	frctl_im_draw(t_mlx *f, int x, int y, int c);

/*
** Creates menu-bar with mlx_put_string();
*/

void    frctl_create_menu_cs(t_mlx *m);

/*
**  Functions:
**  frctl_draw_ship(t_mlx *m), frctl_draw_julia(t_mlx *m), frctl_draw_mandelbrot(t_mlx *m);
**  Description:
**      - image creating(mlx_new_image)
**      - start calculation treads and w8 4 their join.
**      - image destroying(mlx_destroy_image)
*/

void    frctl_draw_ship(t_mlx *m);
void    frctl_draw_julia(t_mlx *m);
void    frctl_draw_mandelbrot(t_mlx *m);

/*
**  Functions:
**  frctl_tread_julia(void *arg), frctl_tread_ship(void *arg), frctl_tread_mandelbrot(void *arg);
**  Description:
**      - starts algorithmic functions for 1/4 of image, depending on the tread number.
*/

void    *frctl_tread_julia(void *arg);
void    *frctl_tread_ship(void *arg);
void    *frctl_tread_mandelbrot(void *arg);

/*
**  Functions:
**  frctl_count_julia(), frctl_count_ship(), frctl_count_mandelbrot();
**  Description:
**      - Fractal calculate core.
*/

void    *frctl_count_julia(t_mlx *m, t_map f, int x, int y);
void    *frctl_count_ship(t_mlx *m, t_map f, int x, int y);
void    *frctl_count_mandelbrot(t_mlx *m, t_map f, int x, int y);

#endif