#include "fractol.h"
int julia_iter(t_complex z, t_fractal *fractal, int x, int y) 
{
    double tmp;
    int offset;
    int i = 0;
    while(i < fractal->iteration)
    {
        tmp = z.real * z.real - z.imagi * z.imagi + fractal->c.real;
        z.imagi = 2 * z.real * z.imagi + fractal->c.imagi;
        z.real = tmp;
        offset = fractal->pic.line_length * y + fractal->pic.bits_per_pixel / 8 * x;
        if (z.real * z.real + z.imagi * z.imagi > 2)
        {
            offset = fractal->pic.line_length * y + fractal->pic.bits_per_pixel / 8 * x;
            *(int *)(fractal->pic.addr + offset) = ft_map(i, fractal->colory, 0x00000, ITERATION);
            return (i);
        }
        *(int *)(fractal->pic.addr + offset) = fractal->colorx;

        i++;
    }
    return (i);
}

void render_julia(t_fractal *fractal)
{
    t_complex z;
    int x;
    int y;
    int offset;
    x = 0;
    while (x < 1000)
    {
        y = 0;
        while(y < 1000)
        {
            z.real = (ft_map(x, -2, 2, 1000) * fractal->mouse ) + fractal->add_x * fractal->mouse; 
            z.imagi = (ft_map(y, 2, -2, 1000) * fractal->mouse ) + fractal->add_y * fractal->mouse;
            julia_iter(z, fractal, x, y);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->pic.img, 0, 0);
}