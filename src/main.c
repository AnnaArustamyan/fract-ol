/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:19:54 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/07 13:45:30 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	fractal.name = av[1];
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		fractal_init(&fractal);
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
	{
		fractal_init(&fractal);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 2);
		exit(EXIT_FAILURE);
	}
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connect);
	return (0);
}
