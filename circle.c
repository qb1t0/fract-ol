#include "includes/fractol.h"
void    frctl_circle(t_mlx *m, int x, int y, int radius) {
    for (int y = -radius; y <= radius; y++)
        for (int x = -radius; x <= radius; x++)
            if (x * x + y * y <= radius * radius)
                frctl_im_draw(m, x + x, y + y, 0xFFFFFF);
}