#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ITERATION 50

typedef struct s_complex{
    double real;
    double imagi;
}t_complex;

typedef struct s_img{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}t_img;

typedef struct s_fractal{
    char name;
    void *mlx;
    void *win;
    char *addr;
    int bits_per_pixel;
    int line_length;
    double mouse;
    double add_x;
    double add_y;
    double iteration;
    double zoom_x;
    double zoom_y;
    int i;
    int colorx;
    int colory;
    t_complex c;
    t_img pic;
}t_fractal;

int close_win(t_fractal *fractal);
void render_julia(t_fractal *fractal);
void render_malb(t_fractal *fractal);
double    ft_map(double un_num, double min, double max, double max1);
double atof(const char *nptr);
int	ft_strcmp(char *s1, char *s2);





#endif
