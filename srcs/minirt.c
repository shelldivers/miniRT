/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:49:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/03 00:17:55 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "key_hook.h"
#include "mlx.h"
#include <stdlib.h>

static void		put_color(t_img *img, int x, int y, unsigned int color);
static t_color	ray_color(t_ray const *ray, t_hit_lst *world);

void	ray_tracing(t_img *img, t_cam *cam, t_vw *vw, t_hit_lst *world)
{
	t_ray	ray;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ray.origin = cam->view_point;
	while (j < img->height)
	{
		i = 0;
		while (i < img->width)
		{
			ray.direction = get_direction(cam, vw, i, j);
			put_color(img, i, j, color_to_int(ray_color(&ray, world)));
			i++;
		}
		j++;
	}
}

void	put_color(t_img *img, int x, int y, unsigned int color)
{
	const int	bytes_per_pixel = img->data.bits_per_pixel / 8;
	int			pos;

	pos = y * (img->data.size_line) + x * bytes_per_pixel;
	*(unsigned int *)(img->addr + pos) = color;
}

t_color	ray_color(t_ray const *ray, t_hit_lst *world)
{
	t_vec3	unit_direction;
	float	a;
	t_rec	rec;

	if (hit_shapes(world, ray, (t_coll){0.0, FLOAT_MAX}, &rec))
		return (vec3_mul(vec3_add(rec.normal, (t_color){1.0, 1.0, 1.0}), 0.5));
	unit_direction = vec3_unit(ray->direction);
	a = 0.5 * (unit_direction.y + 1.0);
	return (vec3_add(vec3_mul((t_color){1.0, 1.0, 1.0}, 1.0 - a), \
		vec3_mul((t_color){0.5, 0.7, 1.0}, a)));
}
