/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:50:21 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/07 13:52:00 by aarustam         ###   ########.fr       */
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
	//MLX
	void	*mlx_connect; //mlx init
	void	*mlx_win;
	char	*name;
	//Img
	t_image	img;
	int		res;
	int		color_main;
	int		color_complimentary;
	double	shift_x;
	double	shift_y;
	double	zoom;
	short	mouse_lock;
	//t_complex	julia;
}	t_fractal;
#endif