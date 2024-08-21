/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:49:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/21 18:39:51 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"
#include "key_hook.h"
#include "mlx.h"
#include "reflection.h"
#include <stdlib.h>

t_color			ray_color(t_rt *rt, t_ray *ray);
static void		put_color(t_img *img, int x, int y, unsigned int color);

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
	t_record	rec;
	t_color		light_color;

	if (hit_shapes(rt->world, ray, (t_coll){0.0, FLOAT_MAX}, &rec))
	{
		light_color = get_phong_reflection_color(rt, &rec);
		return (set_light_color(rec.color, light_color));
	}
	return ((t_color){0, 0, 0});
}

t_color	get_phong_reflection_color(t_rt *rt, t_record *rec)
{
	t_color	light_color;
	int		i;

	light_color = rt->ambient.light;
	i = 0;
	while (i < rt->lights->size)
	{
		if (is_shadowed(rt->lights->objects[i], rec, rt->world))
		{
			i++;
			continue ;
		}
		light_color = light_add(\
			get_diffused_luminance(\
			rec, rt->lights->objects[i]), light_color);
		light_color = light_add(\
			get_specular_luminance(\
			rec, rt->lights->objects[i], &(rt->cam)), light_color);
		i++;
	}
	return (light_color);
}

void	put_color(t_img *img, int x, int y, unsigned int color)
{
	const int	bytes_per_pixel = img->data.bits_per_pixel / 8;
	int			pos;

	pos = y * (img->data.size_line) + x * bytes_per_pixel;
	*(unsigned int *)(img->addr + pos) = color;
}
