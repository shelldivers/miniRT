/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:32 by jiwojung          #+#    #+#             */
/*   Updated: 2024/07/24 20:07:08 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

#define RGB 255.999

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
	int		ir;
	int		ig;
	int		ib;
}				t_color;

int	main(void)
{
	int		image_width;
	int		image_height;
	int		i;
	int		j;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_color	color;

	image_width = 256;
	image_height = 256;
	i = 0;
	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, image_width, image_height, "miniRT");
	img.img = mlx_new_image(mlx, image_width, image_height);
	while (i < image_height)
	{
		j = 0;
		while (j < image_width)
		{
			color.r = (float)j / (image_width - 1);
			color.g = (float)i / (image_height - 1);
			color.b = 0.0;

			color.ir = (int)(RGB * color.r);
			color.ig = (int)(RGB * color.g);
			color.ib = (int)(RGB * color.b);
			mlx_pixel_put(mlx, mlx_win, i, j, (color.ir << 16) + (color.ig << 8) + color.ib);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
