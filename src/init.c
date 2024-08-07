/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:45:39 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/07 13:55:39 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractal_init(t_fractal *fractal, int bonus)
{
	fractal->mlx_connect = mlx_init();
	if (fractal->mlx_connect == NULL)
		exit(EXIT_FAILURE);
	fractal->mlx_win = mlx_new_window(fractal->mlx_connect, \
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_win)
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_win);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connect, WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_win);
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, \
	&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
	events_init(fractal, bonus);
}
