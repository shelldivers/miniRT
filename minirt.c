/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/23 19:24:28 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "sphere.h"
#include "camera.h"
#include "ray.h"
#include "color.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * example.rt
 * 
 * C	-50,0,20	0,0,0	70
 * sp	0,0,20	20	255,0,0
 * A	0.2	255,255,255
 * L	-40,0,30	0.7	255,255,255
 * pl	0,0,0	0,1.0,0	255,0,225
 * cy	50.0,0.0,20.6	0,0,1.0	14.2	21.42	10,0,255
*/
int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_color	c;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	img.ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.ptr, &img.data.bits_per_pixel, \
		&img.data.size_line, &img.data.endian);
	for (int x = 0 ; x < WIDTH ; x++)
	{
		for (int y = 0 ; y < HEIGHT ; y++)
		{
			int r = x % 256;
			int g = y % 256;
			int b = (x + y) % 256;
			c = (t_color){r, g, b};
			put_color(img, x, y, color_to_int(c));
		}	
	}
	mlx_put_image_to_window(mlx, win, img.ptr, 0, 0);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
