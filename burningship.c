#include "includes/fractol.h"
#include "stdlib.h"
void    frctl_draw_ship(t_mlx *m)
{
    pthread_t   *threads;

    m->part = -1;
    m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
    m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->end);
    threads = (pthread_t*)malloc(3 * sizeof(pthread_t));
    pthread_create(&(threads[0]), NULL, frctl_tread_ship, m);
    pthread_create(&(threads[1]), NULL, frctl_tread_ship, m);
    pthread_create(&(threads[2]), NULL, frctl_tread_ship, m);
    frctl_count_ship(m, m->f[0], -1, -1);
    pthread_join(threads[2], NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
    frctl_create_menu_cs(m);
    mlx_destroy_image(m->mlx, m->img);
    mlx_do_sync(m->mlx);
    free(threads);
}

void    *frctl_tread_ship(void *arg)
{
    t_mlx *m;

    m = (t_mlx *)arg;
    m->part++;
    if (m->part == 0)
        frctl_count_ship(m, m->f[3], 399, 399);
    else if (m->part == 1)
        frctl_count_ship(m, m->f[m->part], 399, -1);
    else if (m->part == 2)
        frctl_count_ship(m, m->f[m->part], -1, 399);
}

void    *frctl_count_ship(t_mlx *m, t_map f, int x, int y)
{
    f.hzoom = HLFH * m->zoom;
    f.wzoom = HLFW * m->zoom;
    while (++y < f.ysize)
    {
        f.cim = (y - HLFH) / f.hzoom + m->ymove;
        while (++x < f.xsize) {
            f.i = 0;
            f.nre = 0;
            f.nim = 0;
            f.sre = 0;
            f.cre = (x - HLFW) / f.wzoom + m->xmove;
            while ((f.nre * f.nre + f.nim * f.nim) <= 10.0 && f.i < m->iters)
            {
                f.sre = (f.nre * f.nre) - (f.nim * f.nim) + f.cre;
                f.nim = 2 * fabs(f.nre * f.nim) + f.cim;
                f.nre = f.sre;
                f.i++;
            }
            if (f.i < m->iters && (f.c = m->c + f.i * 65556))
                frctl_im_draw(m, x * m->bpp / 8, y * m->sl, f.c);
        }
        x = -1;
    }
}