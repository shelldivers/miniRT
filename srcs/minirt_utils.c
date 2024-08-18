/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:16:07 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/18 22:15:18 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include <mlx.h>
#include <math.h>

static float	degree_to_radian(float degree);

void	init_mlx(t_rt *rt, t_img *img)
{
	double	aspect_ratio;

	rt->mlx = mlx_init();
	if (!rt->mlx)
		error_exit("mlx_init() failed");
	aspect_ratio = 16.0 / 9.0;
	img->width = 1024;
	img->height = (int)((double)img->width / aspect_ratio);
	if (img->height < 1)
		img->height = 1;
	img->ptr = mlx_new_image(rt->mlx, img->width, img->height);
	if (!img->ptr)
		error_exit("mlx_new_image() failed");
	img->addr = mlx_get_data_addr(img->ptr, &(img->data.bits_per_pixel), \
		&(img->data.size_line), &(img->data.endian));
	if (!img->addr)
		error_exit("mlx_get_data_addr() failed");
	rt->win = mlx_new_window(rt->mlx, img->width, img->height, "miniRT");
	if (!rt->win)
		error_exit("mlx_new_window() failed");
}

void	init_viewport(t_img *img, t_camera *camera, t_viewport *viewport)
{
	t_vec3		look_from;
	t_vec3		look_at;
	t_vec3		view_up;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;
	float		viewport_height;
	float		viewport_width;
	t_vec3		viewport_u;
	t_vec3		viewport_v;

	look_from = camera->view_point;
	look_at = vec3_add(look_from, camera->normal);
	view_up = (t_vec3){0, 1, 0};
	viewport->focal_length = vec3_length(vec3_sub(look_from, look_at));
	viewport_height = 2.0 * tan(degree_to_radian(camera->fov) / 2.0);
	viewport_width = viewport_height * ((float)img->width / img->height);
	w = vec3_unit(vec3_sub(look_from, look_at));
	u = vec3_unit(vec3_cross(view_up, w));
	v = vec3_cross(w, u);
	viewport_u = vec3_mul(u, viewport_width);
	viewport_v = vec3_mul(v, -viewport_height);
	viewport->pixel_delta_u = vec3_div(viewport_u, img->width);
	viewport->pixel_delta_v = vec3_div(viewport_v, img->height);
	viewport->upper_left_corner = vec3_sub(camera->view_point, \
		vec3_mul(w, viewport->focal_length));
	viewport->upper_left_corner = vec3_sub(viewport->upper_left_corner, \
		vec3_div(viewport_u, 2));
	viewport->upper_left_corner = vec3_sub(viewport->upper_left_corner, \
		vec3_div(viewport_v, 2));
	viewport->pixel00_loc = vec3_add(viewport->upper_left_corner, \
		vec3_mul(viewport->pixel_delta_u, 0.5));
	viewport->pixel00_loc = vec3_add(viewport->pixel00_loc, \
		vec3_mul(viewport->pixel_delta_v, 0.5));
}

float	degree_to_radian(float degree)
{
	return (degree * M_PI / 180.0);
}
