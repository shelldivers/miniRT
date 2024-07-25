/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:32 by jiwojung          #+#    #+#             */
/*   Updated: 2024/07/25 17:28:04 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "ray.h"
#include <mlx.h>
#include <stdio.h>
#include <math.h>

#define RGB 255.999

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	draw_sphere(t_data *img, t_color *color, void *mlx_win)
{
	// image
	const float	aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = (int)(image_width / aspect_ratio);

	// camera
	float viewport_height = 2.0;
	float viewport_width = aspect_ratio * viewport_height;
	float focal_length = 1.0;

	t_point3 origin = (t_point3){0, 0, 0};
	t_vec3 horizontal = (t_vec3){viewport_width, 0, 0};
	t_vec3 vertical = (t_vec3){0, viewport_height, 0};
	t_point3 lower_left_corner = vec3_sub((t_vec3)origin, vec3_div(horizontal, 2));
	lower_left_corner = vec3_sub((t_vec3)lower_left_corner, vec3_div(vertical, 2));
	lower_left_corner = vec3_sub((t_vec3)lower_left_corner, (t_vec3){0, 0, focal_length});


	// render
	int		i;
	int		j;
	i = 0;
	j = 0;
	while (i < image_height)
	{
		j = 0;
		while (j < image_width)
		{
			float u = (float)j / (image_width - 1);
			float v = (float)i / (image_height - 1);
			if (hit_sphere((t_point3){0, 0, -1}, 0.5, &(t_ray){origin, vec3_add((t_vec3)lower_left_corner, vec3_add(vec3_mul(horizontal, u), vec3_mul(vertical, v)))}))
			{
				color->x = 1.0;
				color->y = 0.0;
				color->z = 0.0;
			}
			else
			{
				color->x = 0.0;
				color->y = 0.0;
				color->z = 0.0;
			}
			mlx_pixel_put(img->img, mlx_win, j, i, \
			(int)(RGB * color->x) << 16 | (int)(RGB * color->y) << 8 | (int)(RGB * color->z));
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_color	color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	draw_sphere(&img, &color, mlx_win);
	mlx_loop(mlx);
}
