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
