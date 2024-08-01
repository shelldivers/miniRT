/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:32 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/01 15:34:39 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <math.h>
#include "minirt.h"
#include "mlx.h"
#include "color.h"
#include "vec3.h"
#include "ray.h"
#include "ft_bool.h"

// void	draw_background(t_data *img, void *mlx_win)
// {
// 	for (int i = 0; i < WIDTH; ++i)
// 	{
// 		for (int j = 0; j < HEIGHT; ++j)
// 		{
// 			my_mlx_pixel_put(img, mlx_win, i, j, get_rgb(89, 32, 215));
// 		}
// 	}
// }

// float	hit_sphere(const t_vec3 center, float radius, const t_ray *r)
// {
// 	t_vec3	oc;
// 	float	a;
// 	float	b;
// 	float	c;
// 	float	discriminant;

// 	// 이차방정식의 계수 a, b, c 계산
// 	oc = vec3_sub(r->orig, center);
// 	a = vec3_dot(r->dir, r->dir);
// 	b = 2.0 * vec3_dot(oc, r->dir);
// 	c = vec3_dot(oc, oc) - radius * radius;
// 	discriminant = b * b - 4 * a * c;
	
// 	// if discriminant is less than 0, ray does not hit the sphere
// 	if (discriminant < 0) {
// 		return (-1.0);
// 	} else {
// 		// ray hits the sphere and return the closest t
// 		// 이차방정식의 해 (-b ± sqrt(b^2 - 4ac)) / 2a 중에서 작은 값
// 		return (-b - sqrt(discriminant)) / (2.0 * a);
// 	}
// }

float	hit_sphere(const t_vec3 center, float radius, const t_ray *r)
{
	t_vec3	oc;
	float	a;
	float	h;
	float	c;
	float	discriminant;

	// 이차방정식의 계수 a, b, c 계산
	// ray와 sphere의 거리
	oc = vec3_sub(center, r->orig);
	a = vec3_length(r->dir) * vec3_length(r->dir);
	// b = 2.0 * vec3_dot(oc, r->dir);
	h = vec3_dot(r->dir, oc);
	c = vec3_length(oc) * vec3_length(oc) - radius * radius;
	discriminant = h * h - a * c;
	
	// if discriminant is less than 0, ray does not hit the sphere
	if (discriminant < 0) {
		return (-1.0);
	} else {
		// ray hits the sphere and return the closest t
		// 이차방정식의 해 (-b ± sqrt(b^2 - 4ac)) / 2a 중에서 작은 값
		return (h - sqrt(discriminant)) / a;
	}
}

t_vec3	ray_color(const t_ray r)
{
	// for drawing red sphere
	// t_vec3 unit_direction = vec3_unit(r.dir);
    // float a = 0.5 * (unit_direction.y + 1.0);

	// if (hit_sphere(vec3(0, 0, -1), 0.5, &r))
	// 	return vec3(1, 0, 0);

	// for drawing sphere with shading
	float	t;
	t_vec3	unit_vec;
	t_vec3	unit_dir;

	// vec3(0, 0, -1) is center of sphere and 0.5 is radius of sphere
	t = hit_sphere(vec3(0, 0, -1), 0.5, &r);
	// drawing sphere with shading
	if (t > 0.0)
	{
		// get unit vector of hit point
		unit_vec = vec3_unit(vec3_sub(ray_at(&r, t), vec3(0, 0, -1)));
		// 들어온 법선 벡터를 유닛 벡터로 만들어서 0 ~ 1 사이의 값을 가지도록 만듦
		// 크기는 1, 방향은 0 ~ 1 사이의 값
		// 이를 가지고 RGB값으로 반환
		return vec3_mul(vec3(unit_vec.x + 1, unit_vec.y + 1, unit_vec.z + 1), 0.5);
	}

	// for drawing blue sky
	unit_dir = vec3_unit(r.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	return vec3_add(vec3_mul(vec3(1.0, 1.0, 1.0), 1.0 - t), vec3_mul(vec3(0.5, 0.7, 1.0), t));
}

void	draw_sphere(t_data *img, void *mlx_win)
{
	float	aspect_ratio = 16.0 / 9.0;

	// camera and viewport length
	float	focal_length = 1.0;
	// viewport setting
	float	viewport_height = 2.0;
	float	viewport_width = aspect_ratio * viewport_height;

	// camara position
	t_vec3	camera_center = vec3(0, 0, 0);

	// get viewport width and height vector
	t_vec3	viewport_u = vec3(viewport_width, 0, 0);
	t_vec3	viewport_v = vec3(0, -viewport_height, 0);

	// get distance between pixels
	t_vec3	pixel_delta_u = vec3_div(viewport_u, WIDTH);
	t_vec3	pixel_delta_v = vec3_div(viewport_v, HEIGHT);

	// get upper left corner of viewport
	t_vec3	viewport_upper_left = vec3_sub(vec3_sub(camera_center, vec3(0, 0, focal_length)), \
		vec3_add(vec3_div(viewport_u, 2), vec3_div(viewport_v, 2)));

	// get pixel(0, 0) location
	t_vec3	pixel00_loc = vec3_add(viewport_upper_left, vec3_div(vec3_add(pixel_delta_u, pixel_delta_v), 2));

	int i = 0;
	int j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			// get pixel location where ray will be casted
			t_vec3	pixel_center = vec3_add(pixel00_loc, \
				vec3_add(vec3_mul(pixel_delta_u, j), vec3_mul(pixel_delta_v, i)));

			// get ray direction by subtracting camera center from pixel center
			t_vec3 ray_direction = vec3_sub(pixel_center, camera_center);
			// get ray
			t_ray	r = ray(camera_center, ray_direction);
			// get pixel color
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
	// draw_background(&img, vars.win);
	draw_sphere(&img, vars.win);
	printf ("Hello, world!\n");
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}


