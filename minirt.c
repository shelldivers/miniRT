/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:32 by jiwojung          #+#    #+#             */
/*   Updated: 2024/07/31 16:25:27 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"
#include "mlx.h"
#include "color.h"
#include "vec3.h"
#include "ray.h"
#include "ft_bool.h"

void	draw_background(t_data *img, void *mlx_win)
{
	for (int i = 0; i < WIDTH; ++i)
	{
		for (int j = 0; j < HEIGHT; ++j)
		{
			my_mlx_pixel_put(img, mlx_win, i, j, get_rgb(89, 32, 215));
		}
	}
}

t_bool	hit_sphere(const t_vec3 center, float radius, const t_ray *r)
{
	t_vec3	oc;
	float	a;
	float	b;
	float	c;
	float	discriminant;

	oc = vec3_sub(r->orig, center);
	a = vec3_dot(r->dir, r->dir);
	b = 2.0 * vec3_dot(oc, r->dir);
	c = vec3_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant >= 0);
}

t_vec3	ray_color(const t_ray r)
{
	t_vec3 unit_direction = vec3_unit(r.dir);
    float a = 0.5 * (unit_direction.y + 1.0);

	if (hit_sphere(vec3(0, 0, -1), 0.5, &r))
		return vec3(1, 0, 0);
    return vec3_add(vec3_mul(vec3(1.0, 1.0, 1.0), (1.0 - a)), \
		vec3_mul(vec3(0.5, 0.7, 1.0), a));
}

void	draw_sphere(t_data *img, void *mlx_win)
{
	float	aspect_ratio = 16.0 / 9.0;

	float	focal_length = 1.0;
	float	viewport_height = 2.0;
	float	viewport_width = aspect_ratio * viewport_height;
	t_vec3	camera_center = vec3(0, 0, 0);

	t_vec3	viewport_u = vec3(viewport_width, 0, 0);
	t_vec3	viewport_v = vec3(0, -viewport_height, 0);

	t_vec3	pixel_delta_u = vec3_div(viewport_u, WIDTH);
	t_vec3	pixel_delta_v = vec3_div(viewport_v, HEIGHT);

	t_vec3	viewport_upper_left = vec3_sub(vec3_sub(camera_center, vec3(0, 0, focal_length)), \
		vec3_add(vec3_div(viewport_u, 2), vec3_div(viewport_v, 2)));

	t_vec3	pixel00_loc = vec3_add(viewport_upper_left, vec3_div(vec3_add(pixel_delta_u, pixel_delta_v), 2));

	int i = 0;
	int j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			t_vec3	pixel_center = vec3_add(pixel00_loc, \
				vec3_add(vec3_mul(pixel_delta_u, j), vec3_mul(pixel_delta_v, i)));

			t_vec3 ray_direction = vec3_sub(pixel_center, camera_center);
			t_ray	r = ray(camera_center, ray_direction);

			t_vec3 pixel_color = ray_color(r);
			int color = get_rgb((int)(255.999 * pixel_color.x), \
				(int)(255.999 * pixel_color.y), (int)(255.999 * pixel_color.z));

			my_mlx_pixel_put(img, mlx_win, j, i, color);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "miniRT");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(\
		img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_background(&img, vars.win);
	draw_sphere(&img, vars.win);
	printf ("Hello, world!\n");
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}


