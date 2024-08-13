/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:49:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/13 20:13:18 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "key_hook.h"
#include "mlx.h"
#include <stdlib.h>

static void		put_color(t_img *img, int x, int y, unsigned int color);
static t_color	ray_color(t_ray const *ray, t_hit_lst *world);
static void		render_width(t_rt *rt, t_ray *ray, int hei);

void	ray_tracing(t_rt *rt)
{
	t_ray	ray;
	int		hei;
	
	hei = 0;
	ray.origin = rt->cam.view_point;
	while (hei < rt->img.height)
		render_width(rt, &ray, hei++);
}

void	render_width(t_rt *rt, t_ray *ray, int hei)
{
	int 	wid;
	t_color	color;

	wid = 0;
	while (wid < rt->img.width)
	{
		ray->direction = get_direction(&(rt->cam), &(rt->vw), wid, hei);
		color = ray_color(ray, rt->world);
		// color = embient_lighting(color, rt->ambient.light);
		put_color(&(rt->img), wid, hei, color_to_int(color));
		wid++;
	}
}

t_color	ray_color(t_ray const *ray, t_hit_lst *world)
{
	t_ray		scattered;
	t_vec3		direction;
	t_vec3		unit_direction;
	float		a;
	t_record	rec;

	if (hit_shapes(world, ray, (t_coll){0.0, FLOAT_MAX}, &rec))
	{
		direction = random_on_hemisphere(rec.normal);
		scattered = (t_ray){rec.p, direction};
		return (vec3_mul(ray_color(&scattered, world), 0.5));
	}
	unit_direction = vec3_unit(ray->direction);
	a = 0.5 * (unit_direction.y + 1.0);
	return (vec3_add(vec3_mul((t_color){1.0, 1.0, 1.0}, 1.0 - a), \
		vec3_mul((t_color){0.5, 0.7, 1.0}, a)));
}

void	put_color(t_img *img, int x, int y, unsigned int color)
{
	const int	bytes_per_pixel = img->data.bits_per_pixel / 8;
	int			pos;

	pos = y * (img->data.size_line) + x * bytes_per_pixel;
	*(unsigned int *)(img->addr + pos) = color;
}
