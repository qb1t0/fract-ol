#include "includes/fractol.h"

/*
** Setting colors(RGB) for each pixel in 4 bytes of f->im(char *)
*/

void	frctl_im_draw(t_map *f, int x, int y)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		f->im[x * f->bpp / 8 + f->sl * y] = (char)f->c;
		f->im[x * f->bpp / 8 + f->sl * y + 1] = (char)(f->c >> 8);
		f->im[x * f->bpp / 8 + f->sl * y + 2] = (char)(f->c >> 16);
	}
}

double  sqr(double x) { return (x*x); }

void    frctl_count_mandl(t_map *m, int x, int y, int i)
{
    double hzoom;
    double wzoom;

    hzoom = HLFH * m->zoom;
    wzoom = HLFW * m->zoom;
    m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
    m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->end);
    while (++y < HEIGHT) {
        m->cim = (y - HLFH) / hzoom + m->ymove;
        while (++x < WIDTH) {
            m->cre = (x - HLFW) / wzoom + m->xmove;
            m->nre = 0;
            m->nim = 0;
            m->sre = 0;
            m->sim = 0;
            i = 0;
            while ((m->sre + m->sim <= 2.0) && i < 100)
            {
                m->nim = sqr(m->nre + m->nim) - m->sre - m->sim;
                m->nim += m->cim;
                m->nre = m->sre - m->sim + m->cre;
                m->sre = sqr(m->nre);
                m->sim = sqr(m->nim);

                i++;
            }
            i == 100 ? frctl_im_draw(m, x, y) : 0;
        }
        x = -1;
    }
}