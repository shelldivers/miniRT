/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/23 19:44:36 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "sphere.h"
#include "camera.h"
#include "ray.h"
#include "color.h"
#include "libft.h"
#include "vec3.h"
#include <stdio.h>
#include <stdlib.h>

void	init_image(t_img *img, void *mlx)
{
	double	aspect_ratio;

	aspect_ratio = 16.0 / 9.0;
	img->width = 1920;
	img->height = (int)((double)img->width / aspect_ratio);
	if (img->height < 1)
		img->height = 1;
	img->ptr = mlx_new_image(mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->ptr, &(img->data.bits_per_pixel), \
		&(img->data.size_line), &(img->data.endian));
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

void	ray_loop(t_img *img, t_camera *camera, t_viewport *viewport)
{
	t_ray	ray;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ray.origin = camera->view_point;
	while (j < img->height)
	{
		while (i < img->width)
		{
			ray.direction = get_direction(camera, viewport, i, j);
			put_color(img, i, j, color_to_int(ray_color(&ray)));
			i++;
		}
		j++;
	}
}

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
	void		*mlx;
	void		*win;
	t_img		img;
	t_camera	camera;
	t_viewport	viewport;

	mlx = mlx_init();
	init_image(&img, mlx);
	win = mlx_new_window(mlx, img.width, img.height, "miniRT");
	camera.view_point = (t_vec3){0, 0, 0};
	camera.normal = (t_vec3){0, 0, 0};
	camera.fov = 70;
	init_viewport(&img, &camera, &viewport);
	ray_loop(&img, &camera, &viewport);
	mlx_put_image_to_window(mlx, win, img.ptr, 0, 0);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
