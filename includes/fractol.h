#ifndef FRACTOL_LIBRARY_H
# define FRACTOL_LIBRARY_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# define WIDTH 1000
# define HEIGHT 1000
# define HLFW 500
# define HLFH 500

/*
**  struct s_o uses for 1 pixel representation
** x,y,z : axis coordinates
**     c : 4-bytes color representation (RGBA)
*/

typedef struct	s_o{
    float		x;
    float		y;
    float		z;
    int			c;
}				t_o;

/*
**  struct s_map uses for collecting data about the drawing picture
**  ToDo: add variables description here
*/

typedef struct	s_map{
/* variables needed by the mlx library functions*/
    void		*mlx;
    void		*win;
    void		*img;
    char		*im;
    int			bpp;
    int         end;
    int			sl;
    int         c;
/*Fractol variables*/
    double      cre;  //current real part of the "c" const(shape for)
    double      cim;  //current imaginary part
    double      nre;  //new real part
    double      nim;  //new imaginary part
    double      sre;  // real part
    double      sim;  //old imaginary part
    double		zoom; //zoom in/out
    double		xmove;//move on x axis
    double		ymove;//move on y axis
    short       iters;
/* variables needed by Bresenham algorithm functions*/
    int			e;
    int			dx;
    int			dy;
    int			dh;
    int			de;
    int			incdeltay;
    int			incdeltax;
    int			incr_x;
    int			incr_y;
/* drawing image pixel array*/
    t_o			**f;
}				t_map;

void	frctl_im_draw(t_map *f, int x, int y);
int     fractol_onbutton(int button, t_map *m);
void    frctl_count_mandl(t_map *m, int x, int y, int i);

#endif