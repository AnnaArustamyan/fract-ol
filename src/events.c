/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:21:50 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/07 20:13:49 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_handler(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx_connect, fract->mlx_win);
	exit(0);
}

int	key_handler(int keysym, t_fractal *fract)
{
	if (keysym == 53)
		close_handler(fract);
	else if (keysym == 123)
		fract->shift_x -= (0.5 * fract->zoom);
	else if (keysym == 124)
		fract->shift_x += (0.5 * fract->zoom);
	else if (keysym == 126)
		fract->shift_y += (0.5 * fract->zoom);
	else if (keysym == 125)
		fract->shift_y -= (0.5 * fract->zoom);
	else if (keysym == 69)
		fract->resolution += 10;
	else if (keysym == 78)
		fract->resolution -= 10;
	destroy(fract);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fract)
{
	(void)x;
	(void)y;
	if (button == 5)
		fract->zoom *= 0.9;
	else if (button == 4)
		fract->zoom *= 1.05;
	destroy(fract);
	return (0);
}

void	destroy(t_fractal *fract)
{
	mlx_clear_window(fract->mlx_connect, fract->mlx_win);
	fractal_render(fract);
}

int	julia_track(int x, int y, t_fractal *fract)
{
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		fract->julia.re = (map(x, -2, +2, WIDTH) * fract->zoom)
			+ fract->shift_x;
		fract->julia.im = (map(y, +2, -2, HEIGHT)
				* fract->zoom) + fract->shift_y;
		destroy(fract);
	}
	return (0);
}
