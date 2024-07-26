/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:51:40 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 23:13:24 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "error.h"
#include "minirt.h"
#include "mlx.h"
#include "vec3.h"
#include <math.h>

void	init_image(void *mlx, t_img *img)
{
	double	aspect_ratio;

	aspect_ratio = 16.0 / 9.0;
	img->width = 1024;
	img->height = (int)((double)img->width / aspect_ratio);
	if (img->height < 1)
		img->height = 1;
	img->ptr = mlx_new_image(mlx, img->width, img->height);
	if (!img->ptr)
		error_exit("mlx_new_image() failed");
	img->addr = mlx_get_data_addr(img->ptr, &(img->data.bits_per_pixel), \
		&(img->data.size_line), &(img->data.endian));
	if (!img->addr)
		error_exit("mlx_get_data_addr() failed");
}

void	init_viewport(t_img *img, t_camera *camera, t_viewport *viewport)
{
	float		viewport_height;
	float		viewport_width;
	t_vec3		viewport_u;
	t_vec3		viewport_v;

	viewport->focal_length = 1.0;
	viewport_height = 2.0;
	viewport_width = viewport_height * ((float)img->width / img->height);
	viewport_u = (t_vec3){viewport_width, 0, 0};
	viewport_v = (t_vec3){0, -viewport_height, 0};
	viewport->pixel_delta_u = vec3_div(viewport_u, img->width);
	viewport->pixel_delta_v = vec3_div(viewport_v, img->height);
	viewport->upper_left_corner = vec3_sub(camera->view_point, \
		(t_vec3){0, 0, viewport->focal_length});
	viewport->upper_left_corner = vec3_sub(viewport->upper_left_corner, \
		vec3_div(viewport_u, 2));
	viewport->upper_left_corner = vec3_sub(viewport->upper_left_corner, \
		vec3_div(viewport_v, 2));
	viewport->pixel00_loc = vec3_add(viewport->upper_left_corner, \
		vec3_mul(viewport->pixel_delta_u, 0.5));
	viewport->pixel00_loc = vec3_add(viewport->pixel00_loc, \
		vec3_mul(viewport->pixel_delta_v, 0.5));
}

void	put_color(t_img *img, int x, int y, unsigned int color)
{
	const int	bytes_per_pixel = img->data.bits_per_pixel / 8;
	int			pos;

	pos = y * (img->data.size_line) + x * bytes_per_pixel;
	*(unsigned int *)(img->addr + pos) = color;
}

t_color	ray_color(t_ray const *ray, t_hittable_list *world)
{
	t_vec3			unit_direction;
	float			a;
	t_hit_record	rec;

	if (hit_shapes(world, ray, 0.0, FLOAT_MAX, &rec))
		return (vec3_mul(vec3_add(rec.normal, (t_color){1.0, 1.0, 1.0}), 0.5));
	unit_direction = vec3_unit(ray->direction);
	a = 0.5 * (unit_direction.y + 1.0);
	return (vec3_add(vec3_mul((t_color){1.0, 1.0, 1.0}, 1.0 - a), \
		vec3_mul((t_color){0.5, 0.7, 1.0}, a)));
}
