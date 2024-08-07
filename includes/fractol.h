/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:50:21 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/07 20:14:45 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"

# define ERROR_MSG "please enter \n\"./fractol mandelbrot\"\
			or \n\"./fractol julia <val 1> <val 2>\"\n"
# define WIDTH 800
# define HEIGHT 800

//colors
# define DARK_GREEN          0x003300
# define LIGHT_GREEN         0x00FF00
# define LIME                0xCCFF33
# define BLACK               0x000000
# define ORANGE              0xFF4500
# define WHITE               0xFFFFFF
# define DEEP_RED            0x330000
# define YELLOW              0xFFFF00
# define DEEP_BLUE           0x000033
# define CYAN                0x00FFFF
# define BLACK               0x000000
# define WHITE               0xFFFFFF
# define RED                 0xFF0000
# define GREEN               0x00FF00
# define BLUE                0x0000FF
# define YELLOW              0xFFFF00
# define CYAN                0x00FFFF
# define MAGENTA             0xFF00FF
# define SILVER              0xC0C0C0
# define GRAY                0x808080
# define MAROON              0x800000
# define OLIVE               0x808000
# define PURPLE              0x800080
# define TEAL                0x008080
# define NAVY                0x000080
# define PINK                0xFFC0CB
# define HOT_PINK            0xFF69B4
# define LIGHT_PINK          0xFFB6C1
# define DEEP_PINK           0xFF1493
# define PALE_VIOLET_RED     0xDB7093
# define MEDIUM_VIOLET_RED   0xC71585
# define VIOLET_RED          0xD02090
# define DARK_VIOLET         0x9400D3
# define DARK_MAGENTA        0x8B008B
# define MAGENTA             0xFF00FF
# define PURPLE              0x800080
# define INDIGO              0x4B0082

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractal
{
	// MLX
	void		*mlx_connect; // mlx init
	void		*mlx_win;
	char		*name;
	// Img
	t_image		img;
	double		hypotenuse;
	int			resolution;
	double		shift_x;
	double		shift_y;
	double		zoom;
	t_complex	julia;
}	t_fractal;

void		malloc_error(void);
void		fractal_init(t_fractal *fractal);
double		map(double unscaled_num, double new_min, \
					double new_max, double old_max);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	square_complex(t_complex a);
void		fractal_render(t_fractal *fractal);
void		handle_pixel(int x, int y, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_image *img, int color);
int			julia_track(int x, int y, t_fractal *fract);
void		destroy(t_fractal *fract);
int			mouse_handler(int button, int x, int y, t_fractal *fract);
int			key_handler(int keysym, t_fractal *fract);
int			close_handler(t_fractal *fract);
double		float_atoi(char *s);
#endif