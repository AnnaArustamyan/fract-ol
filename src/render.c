/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:25:54 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/07 20:19:08 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	c_init(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!(ft_strncmp(fractal->name, "mandelbrot", 10)))
	{
		c->re = z->re;
		c->im = z->im;
	}
	else
	{
		c->re = fractal->julia.re;
		c->im = fractal->julia.im;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			n;
	int			color;

	z.re = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.im = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c_init(&z, &c, fractal);
	n = 0;
	while (n < fractal->resolution)
	{
		z = complex_add(square_complex(z), c);
		if ((z.re * z.re) + (z.im * z.im) > fractal->hypotenuse)
		{
			color = map(n, DARK_MAGENTA, WHITE, fractal->resolution);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++n;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connect, fractal->mlx_win, \
			fractal->img.img_ptr, 0, 0);
}
