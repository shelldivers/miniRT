/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:16:07 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 10:55:41 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include <mlx.h>
#include <math.h>

static t_vw_var	init_viewport_variable(t_rt *rt);
static t_vec3	get_upper_left_corner(t_rt *rt, t_vw_var var);
static t_vec3	get_pixel00_loc(t_rt *rt, t_vec3 upper_left_corner);

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

/**
 * @brief Initialize the viewport
 * @see https://ko.fm/7L7
 * @param rt
 * @return void
 */
void	init_viewport(t_rt *rt)
{
	t_vw_var	var;

	var = init_viewport_variable(rt);
	rt->vw.focal_length = vec3_length(vec3_sub(var.look_from, var.look_at));
	rt->vw.pixel_delta_u = vec3_div(var.viewport_u, rt->img.width);
	rt->vw.pixel_delta_v = vec3_div(var.viewport_v, rt->img.height);
	rt->vw.upper_left_corner = get_upper_left_corner(rt, var);
	rt->vw.pixel00_loc = get_pixel00_loc(rt, rt->vw.upper_left_corner);
}

t_vw_var	init_viewport_variable(t_rt *rt)
{
	t_vw_var	var;

	var.look_from = rt->cam.view_point;
	var.look_at = vec3_add(var.look_from, rt->cam.normal);
	var.view_up = (t_vec3){0, 1, 0};
	var.viewport_height = 2.0 * tan(rt->cam.fov * M_PI / 180.0 / 2.0);
	var.viewport_width = var.viewport_height \
		* ((float)rt->img.width / rt->img.height);
	var.w = vec3_unit(vec3_sub(var.look_from, var.look_at));
	var.u = vec3_unit(vec3_cross(var.view_up, var.w));
	var.v = vec3_cross(var.w, var.u);
	var.viewport_u = vec3_mul(var.u, var.viewport_width);
	var.viewport_v = vec3_mul(var.v, -var.viewport_height);
	return (var);
}

t_vec3	get_upper_left_corner(t_rt *rt, t_vw_var var)
{
	t_vec3	upper_left_corner;

	upper_left_corner = vec3_sub(rt->cam.view_point, \
		vec3_mul(var.w, rt->vw.focal_length));
	upper_left_corner = vec3_sub(upper_left_corner, \
		vec3_div(var.viewport_u, 2));
	upper_left_corner = vec3_sub(upper_left_corner, \
		vec3_div(var.viewport_v, 2));
	return (upper_left_corner);
}

t_vec3	get_pixel00_loc(t_rt *rt, t_vec3 upper_left_corner)
{
	t_vec3	pixel00_loc;

	pixel00_loc = vec3_add(upper_left_corner, \
		vec3_mul(rt->vw.pixel_delta_u, 0.5));
	pixel00_loc = vec3_add(pixel00_loc, \
		vec3_mul(rt->vw.pixel_delta_v, 0.5));
	return (pixel00_loc);
}
