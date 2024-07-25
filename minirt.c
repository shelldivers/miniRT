/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/25 23:26:23 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "color.h"
#include "error.h"
#include "key_hook.h"
#include "minirt.h"
#include "mlx.h"
#include "ray.h"
#include "vec3.h"
#include <stdio.h>
#include <stdlib.h>

void	ray_tracing(t_img *img, t_camera *camera, t_viewport *viewport);

int	main(void)
{
	t_minirt	rt;
	t_img		img;
	t_camera	camera;
	t_viewport	viewport;

	rt.mlx = mlx_init();
	if (!rt.mlx)
		error_exit("mlx_init() failed");
	init_image(rt.mlx, &img);
	rt.win = mlx_new_window(rt.mlx, img.width, img.height, "miniRT");
	if (!rt.win)
		error_exit("mlx_new_window() failed");
	camera.view_point = (t_vec3){0, 0, 0};
	camera.normal = (t_vec3){0, 0, 0};
	camera.fov = 70;
	init_viewport(&img, &camera, &viewport);
	ray_tracing(&img, &camera, &viewport);
	mlx_put_image_to_window(rt.mlx, rt.win, img.ptr, 0, 0);
	mlx_hook(rt.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &rt);
	mlx_hook(rt.win, X_EVENT_DESTROY, 0L, destroy_minirt, &rt);
	mlx_loop(rt.mlx);
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
