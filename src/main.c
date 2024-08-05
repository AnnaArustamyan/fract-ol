/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:19:54 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/05 22:31:46 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		ft_printf("mandelbrot\n");
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
	{
		ft_printf("julia\n");
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
