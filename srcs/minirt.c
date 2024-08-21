/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:49:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/21 13:46:53 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "minirt.h"
#include "key_hook.h"
#include "mlx.h"
#include <stdlib.h>

t_color		ray_color(t_rt *rt, t_ray *ray);
static void	set_color(t_rt *rt, t_record *rec);
static void	put_color(t_img *img, int x, int y, unsigned int color);

void	ray_tracing(t_rt *rt)
{
	t_ray	ray;
	int		hei;
	int		wid;
	t_color	color;

	hei = 0;
	ray.origin = rt->cam.view_point;
	while (hei < rt->img.height)
	{
		wid = 0;
		while (wid < rt->img.width)
		{
			ray.direction = get_direction(&(rt->cam), &(rt->vw), wid, hei);
			color = ray_color(rt, &ray);
			put_color(&(rt->img), wid, hei, color_to_int(color));
			wid++;
		}
		hei++;
	}
}

t_color	ray_color(t_rt *rt, t_ray *ray)
{
	t_vec3		unit_direction;
	float		a;
	t_record	rec;

	if (hit_shapes(rt->world, ray, (t_coll){0.0, FLOAT_MAX}, &rec))
	{
		set_color(rt, &rec);
		return (rec.color);
	}
	unit_direction = vec3_unit(ray->direction);
	a = 0.5 * (unit_direction.y + 1.0);
	return (vec3_add(vec3_mul((t_color){1.0, 1.0, 1.0}, 1.0 - a), \
		vec3_mul((t_color){0.5, 0.7, 1.0}, a)));
}

/*
* @brief every reflection is calculating here
* @param ray
* @param rec
* @param ambient
* @param lights
* @return void
*/
static void	set_color(t_rt *rt, t_record *rec)
{
	int		i;
	t_color	light_color;

	i = 0;
	light_color = rt->ambient.light;
	while (i < rt->lights->size)
	{
		if (!is_shadowed(rt->lights->objects[i], rec, rt->world))
		{
			light_color = light_add(\
				get_diffused_luminance(\
				rec, rt->lights->objects[i]), light_color);
			light_color = light_add(\
				get_specular_luminance(\
				rec, rt->lights->objects[i], &(rt->cam)), light_color);
		}
		i++;
	}
	rec->color = illuminate_object(light_color, rec->color);
}

void	put_color(t_img *img, int x, int y, unsigned int color)
{
	const int	bytes_per_pixel = img->data.bits_per_pixel / 8;
	int			pos;

	pos = y * (img->data.size_line) + x * bytes_per_pixel;
	*(unsigned int *)(img->addr + pos) = color;
}
