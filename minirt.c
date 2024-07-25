/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 03:04:11 by jeongwpa         ###   ########.fr       */
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
#include "hittable.h"
#include "sphere.h"
#include <stdio.h>
#include <stdlib.h>

void	ray_tracing(t_img *img, t_camera *camera, t_viewport *viewport, t_hittable_list *world);

t_hittable_list *init_world(t_hittable_list *world, t_camera *camera, char *filename)
{
	t_hittable	*shape;

	(void)filename;
	camera->view_point = (t_vec3){0, 0, 0};
	camera->normal = (t_vec3){0, 0, 0};
	camera->fov = 70;
	world = init_hittable_list(10);
	if (!world)
		error_exit("init_hittable_list() failed");
	// TODO: Parse the scene file and add objects to the world
	shape = (t_hittable *)init_sphere((t_vec3){0, 0, -1}, 0.5, (t_color){1, 0, 0});
	add_hittable_list(world, shape);
	shape = (t_hittable *)init_sphere((t_vec3){0, 1, -1}, 0.5, (t_color){0, 1, 0});
	add_hittable_list(world, shape);
	shape = (t_hittable *)init_sphere((t_vec3){1, 0, -1}, 0.5, (t_color){0, 0, 1});
	add_hittable_list(world, shape);
	shape = (t_hittable *)init_sphere((t_vec3){1, 1, -1}, 0.5, (t_color){0, 1, 0});
	add_hittable_list(world, shape);
	shape = (t_hittable *)init_sphere((t_vec3){0, -1, -1}, 0.5, (t_color){1, 1, 0});
	add_hittable_list(world, shape);
	shape = (t_hittable *)init_sphere((t_vec3){-1, 0, -1}, 0.5, (t_color){0, 1, 1});
	add_hittable_list(world, shape);
	shape = (t_hittable *)init_sphere((t_vec3){-1, -1, -1}, 0.5, (t_color){1, 1, 1});
	add_hittable_list(world, shape);
	shape = (t_hittable *)init_sphere((t_vec3){-1, 1, -1}, 0.5, (t_color){1, 0, 1});
	add_hittable_list(world, shape);
	shape = (t_hittable *)init_sphere((t_vec3){1, -1, -1}, 0.5, (t_color){0, 1, 0});
	add_hittable_list(world, shape);
	return (world);
}

int	main(int argc, char **argv)
{
	t_minirt	rt;
	t_img		img;
	t_camera	camera;
	t_viewport	viewport;

	if (argc < 2)
		error_exit("Usage: ./miniRT [scene.rt]");
	rt.mlx = mlx_init();
	if (!rt.mlx)
		error_exit("mlx_init() failed");
	init_image(rt.mlx, &img);
	rt.win = mlx_new_window(rt.mlx, img.width, img.height, "miniRT");
	if (!rt.win)
		error_exit("mlx_new_window() failed");
	rt.world = init_world(rt.world, &camera, argv[1]);
	init_viewport(&img, &camera, &viewport);
	ray_tracing(&img, &camera, &viewport, rt.world);
	mlx_put_image_to_window(rt.mlx, rt.win, img.ptr, 0, 0);
	mlx_hook(rt.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &rt);
	mlx_hook(rt.win, X_EVENT_DESTROY, 0L, destroy_minirt, &rt);
	mlx_loop(rt.mlx);
	return (EXIT_SUCCESS);
}

void	ray_tracing(t_img *img, t_camera *camera, t_viewport *viewport, t_hittable_list *world)
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
			put_color(img, i, j, color_to_int(ray_color(&ray, world)));
			i++;
		}
		j++;
	}
}
