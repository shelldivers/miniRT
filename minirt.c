/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:32 by jiwojung          #+#    #+#             */
/*   Updated: 2024/07/26 18:15:31 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include "color.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>


int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "miniRT");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(\
		img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < WIDTH; ++i)
	{
		for (int j = 0; j < HEIGHT; ++j)
		{
			my_mlx_pixel_put(&img, vars.win, i, j, 0x00FFFFFF);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, void *mlx_win, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + \
		(y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = mlx_get_color_value(mlx_win, color);
}
