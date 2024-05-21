#include "fractol.h"

int malb_iter(t_complex c, t_fractal *fractal, int x, int y) 
{
    t_complex z;
    double tmp;
    int offset;
    int i = 0;
    z.real = 0;
    z.imagi = 0;
    while(i < fractal->iteration)
    {
        tmp = z.real * z.real - z.imagi * z.imagi + c.real;
        z.imagi = 2 * z.real * z.imagi + c.imagi;
        z.real = tmp;
        offset = fractal->pic.line_length * y + fractal->pic.bits_per_pixel / 8 * x;
        if (z.real * z.real + z.imagi * z.imagi > 4)
        {
            offset = fractal->pic.line_length * y + fractal->pic.bits_per_pixel / 8 * x;
            *(int *)(fractal->pic.addr + offset) = ft_map(i, 0xFFFFF, fractal->colory, ITERATION);
            return (i);
        }
        *(int *)(fractal->pic.addr + offset) = fractal->colorx;

        i++;
    }
    return (i);

}

void render_malb(t_fractal *fractal)
{
    t_complex c;
    int x;
    int y;
    int offset;
    char *pixel;
    x = 0;
    c.real = -2.5;
    c.imagi = 1.5;
    while (x < 1000)
    {
        y = 0;
        while(y < 1000)
        {
            c.imagi = (ft_map(y, 2, -2, 1000) * fractal->mouse) + fractal->add_y ;
            c.real = (ft_map(x, -2, 2, 1000) * fractal->mouse) + fractal->add_x ;
            malb_iter(c, fractal, x, y);
            y++;
        }
        c.real += 0.004;
        x++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->pic.img, 0, 0);
}
