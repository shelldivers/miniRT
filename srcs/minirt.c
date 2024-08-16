/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:49:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/16 18:06:12 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "minirt.h"
#include "key_hook.h"
#include "mlx.h"
#include <stdlib.h>

t_color		ray_color(\
					t_ray const *ray, \
					t_hit_lst *world, \
					t_ambient ambient, \
					t_light_lst *lights);
static void	set_color(\
						t_ray const *ray, \
						t_record *rec, \
						t_ambient ambient, \
						t_light_lst *lights);
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
			color = ray_color(&ray, rt->world, rt->ambient, rt->lights);
			put_color(&(rt->img), wid, hei, color_to_int(color));
			wid++;
		}
		hei++;
	}
}

t_color	ray_color(\
					t_ray const *ray, \
					t_hit_lst *world, \
					t_ambient ambient, \
					t_light_lst *lights)
{
	t_vec3		unit_direction;
	float		a;
	t_record	rec;

	if (hit_shapes(world, ray, (t_coll){0.0, FLOAT_MAX}, &rec))
	{
		set_color(ray, &rec, ambient, lights);
		return (rec.color);
	}
	unit_direction = vec3_unit(ray->direction);
	a = 0.5 * (unit_direction.y + 1.0);
	return (vec3_add(vec3_mul((t_color){1.0, 1.0, 1.0}, 1.0 - a), \
		vec3_mul((t_color){0.5, 0.7, 1.0}, a)));
}

// ㅇㅕ기서 ambient 적용하고
// diffuse도 적용해야함
// specular도 적용해야함
static void	set_color(\
						t_ray const *ray, \
						t_record *rec, \
						t_ambient ambient, \
						t_light_lst *lights)
{
	int		i;
	t_color	ambient_color;
	t_color	diffused_color;
	// t_color	specular_color;
	if (!ray)
		i = 0;
	i = 0;
	ambient_color = vec3_mul_vec(rec->color, ambient.light);
	while (i < lights->size)
	{
		diffused_color = get_diffused(rec, lights->objects[i]);
		rec->color = mix_color(rec->color, diffused_color);
		i++;
	}
}

void	put_color(t_img *img, int x, int y, unsigned int color)
{
	const int	bytes_per_pixel = img->data.bits_per_pixel / 8;
	int			pos;

	pos = y * (img->data.size_line) + x * bytes_per_pixel;
	*(unsigned int *)(img->addr + pos) = color;
}
