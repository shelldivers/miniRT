/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:47:03 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/25 02:47:24 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_anti_aliased_color(t_rt *rt, t_ray ray, int wid, int hei)
{
	t_color	color;
	int		sample_count;

	color = (t_color){0, 0, 0};
	sample_count = 0;
	while (sample_count < SAMPLE_PER_PIXEL)
	{
		ray.direction = get_direction(&(rt->cam), &(rt->vw), wid, hei);
		color = vec3_add(color, ray_color(rt, &ray));
		sample_count++;
	}
	return (vec3_div(color, SAMPLE_PER_PIXEL));
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

	light_color = vec3_mul(rt->ambient.light, AMBIENT_CONST);
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
