#ifndef	FRACTOL_H
# define	FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"


typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_image
{
	void	*img;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractal
{
	//MLX
	void	*mlx_connect; //mlx init
	void	*mlx_win;
	char 	*name;
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

#define ERROR_MSG "please enter \n\"./fractol mandelbrot\" or \n\"./fractol julia <val 1> <val 2>\"\n"

#endif