#include "fractol.h"


int close_win(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx, fractal->pic.img);
    mlx_destroy_window(fractal->mlx, fractal->win);
    exit(0);
}

double    ft_map(double un_num, double min, double max, double max1){
         return ((max - min) * (un_num - 0) / (max1 - 0) + min); 
}

int key_event(int keycode, t_fractal *fractal)
{
    if (keycode == 53)
        close_win(fractal);
    else if (keycode == 126)
        fractal->add_y += 0.1;
    else if (keycode == 8)
        fractal->colorx += 0x0000CB;
    else if (keycode == 9)
        fractal->colory += 0x0F00FB;
    else if (keycode == 125)
        fractal->add_y -= 0.1;
    else if (keycode == 123)
        fractal->add_x -= 0.1;
    else if (keycode == 124)
        fractal->add_x += 0.1;
    else if (keycode == 69)
        fractal->iteration += 10;
    else if (keycode == 78)
        fractal->iteration -= 10;
    else 
        return (0);
    if (fractal->name == 'j')
        render_julia(fractal);
    else if (fractal->name == 'm')
        render_malb(fractal);
    return (0);
}

int mouse_event(int button, int x, int y, t_fractal *fractal)
{
    if (button == 4)
    {
        fractal->mouse *= 1.1;
    }
    else if (button == 5)
    {
        fractal->mouse *= 0.9;
    }
    if (fractal->name == 'j')
        render_julia(fractal);
    else if (fractal->name == 'm')
        render_malb(fractal);
    return (0);
}
 void   init_struct(t_fractal *fractal)
 {
    fractal->mlx = mlx_init();
    fractal->win = mlx_new_window(fractal->mlx, 1000, 1000, "Fractol");
    fractal->pic.img = mlx_new_image(fractal->mlx, 1000, 1000);
    fractal->pic.addr = mlx_get_data_addr(fractal->pic.img, &fractal->pic.bits_per_pixel, &fractal->pic.line_length, &fractal->pic.endian);
    fractal->add_x = 0;
    fractal->add_y = 0;
    fractal->mouse = 1;
    fractal->i = 0;
    fractal->iteration = ITERATION;
    fractal->colorx = 0xFFC0CB;
    fractal->colory = 0x0000FF;
    fractal->zoom_x = 0;
    fractal->zoom_y = 0;
 }

 void   check_fractal(char *str, t_fractal *fractal)
 {
     if (ft_strcmp(str, "julia") == 0)
         fractal->name = 'j';
     else if (ft_strcmp(str, "mandelbrot") == 0)
         fractal->name = 'm';
     else
     {
        printf("Usage: ./fractol julia c_real c_imaginary\n OR \n");
        printf("Usage: ./fractol mandelbrot\n OR\n");
         exit(0);
     }
 }

int main(int argc, char **argv)
{
    t_fractal fractal;
    t_complex c;
    init_struct(&fractal);
    check_fractal(argv[1],&fractal);
    if (fractal.name == 'j')
    {
        if (argc != 4)
        {
            printf("Usage: ./fractol julia c_real c_imaginary\n");
            exit(0);
        }
        fractal.c.real = atof(argv[2]);
        fractal.c.imagi = atof(argv[3]);
        render_julia(&fractal);
    }    else if (fractal.name == 'm')
    {
        if (argc != 2)
        {
            printf("Usage: ./fractol mandelbrot\n");
            exit(0);
        }
        render_malb(&fractal);
    }
    mlx_hook(fractal.win,2,0,key_event,&fractal);
    mlx_mouse_hook(fractal.win,mouse_event,&fractal);
    mlx_hook(fractal.win,17,0,close_win,&fractal);
    mlx_loop(fractal.mlx);
}