/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:16:07 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/03 00:42:53 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include "mlx.h"
#include "libft.h"
#include "shape/sphere.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

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

void	init_world(t_cam *cam, t_hit_lst *world, char *filename)
{
	int		fd;

	must_be_rt_extension(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(ERROR_OPEN_FILE);
	world = init_hittable_list(10);
	parse_rtfile(fd, cam, world);
}

void	parse_rtfile(int fd, t_cam *cam, t_hit_lst *world)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == 'A' && ft_isspace(line[1]))
			parse_ambient(line, cam, world);
		else if (line[0] == 'C' && ft_isspace(line[1]))
			parse_camera(line, cam);
		else if (line[0] == 'L' && ft_isspace(line[1]))
			parse_light(line, cam, world);
		else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
			parse_plane(line, world);
		else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
			parse_sphere(line, world);
		else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
			parse_cylinder(line, world);
		else
			error_exit(ERROR_INVALID_IDENTIFIER);
		free(line);
	}
}

void	init_viewport(t_img *img, t_cam *camera, t_vw *viewport)
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
