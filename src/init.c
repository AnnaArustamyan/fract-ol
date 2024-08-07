/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:45:39 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/07 19:40:04 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	malloc_error(void)
{
	perror("malloc error");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->hypotenuse = 4;
	fractal->resolution = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	events_init(t_fractal *fract)
{
	mlx_key_hook(fract->mlx_win, key_handler, fract);
	mlx_mouse_hook(fract->mlx_win, mouse_handler, fract);
	mlx_hook(fract->mlx_win, 17, 0, close_handler, fract);
	mlx_hook(fract->mlx_win, 6, 0, julia_track, fract);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connect = mlx_init();
	if (fractal->mlx_connect == NULL)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_connect, \
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_win)
	{
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_win);
		free(fractal->mlx_win);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connect, WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_win);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len,
			&fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
