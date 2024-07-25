/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/25 22:51:58 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "color.h"
#include "error.h"
#include "minirt.h"
#include "mlx.h"
#include "ray.h"
#include "vec3.h"
#include <stdio.h>
#include <stdlib.h>

void	ray_tracing(t_img *img, t_camera *camera, t_viewport *viewport);

int	main(void)
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_camera	camera;
	t_viewport	viewport;

	mlx = mlx_init();
	if (!mlx)
		error_exit("mlx_init() failed");
	init_image(&img, mlx);
	win = mlx_new_window(mlx, img.width, img.height, "miniRT");
	if (!win)
		error_exit("mlx_new_window() failed");
	camera.view_point = (t_vec3){0, 0, 0};
	camera.normal = (t_vec3){0, 0, 0};
	camera.fov = 70;
	init_viewport(&img, &camera, &viewport);
	ray_tracing(&img, &camera, &viewport);
	mlx_put_image_to_window(mlx, win, img.ptr, 0, 0);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}

void	ray_tracing(t_img *img, t_camera *camera, t_viewport *viewport)
{
	t_ray	ray;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ray.origin = camera->view_point;
	while (j < img->height)
	{
		i = 0;
		while (i < img->width)
		{
			ray.direction = get_direction(camera, viewport, i, j);
			put_color(img, i, j, color_to_int(ray_color(&ray)));
			i++;
		}
		j++;
	}
}
