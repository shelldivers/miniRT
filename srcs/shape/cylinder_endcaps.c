/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_endcaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:39:29 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/14 02:00:59 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/cylinder.h"
#include <math.h>

static t_bool	is_collided_endcaps(\
	t_cylinder *cy, t_ray const *ray, t_coll t, float *root);
static float	is_collided_top(t_cylinder *cy, t_ray const *ray, t_coll t);
static float	is_collided_bottom(t_cylinder *cy, t_ray const *ray, t_coll t);


float	hit_cylinder_endcaps(t_cylinder *cy, t_ray const *ray, t_coll t)
{
	float		root;

	if (!is_collided_endcaps(cy, ray, t, &root))
		return (FLOAT_MAX);
	return (root);
}

t_bool	is_collided_endcaps(\
	t_cylinder *cy, t_ray const *ray, t_coll t, float *root)
{
	float	top_t;
	float	bottom_t;

	top_t = is_collided_top(cy, ray, t);
	bottom_t = is_collided_bottom(cy, ray, t);
	if (top_t == FLOAT_MAX && bottom_t == FLOAT_MAX)
		return (FALSE);
	*root = bottom_t;
	if (top_t < bottom_t)
		*root = top_t;
	return (TRUE);
}

float	is_collided_top(t_cylinder *cy, t_ray const *ray, t_coll t)
{
	float	denominator;
	t_vec3	top;
	float	top_t;
	float	length;

	denominator = vec3_dot(ray->direction, cy->normal);
	if (denominator == 0)
		return (FLOAT_MAX);
	top = vec3_sub(cy->top, ray->origin);
	top_t = vec3_dot(top, cy->normal) / denominator;
	if (top_t <= t.min || t.max <= top_t)
		return (FLOAT_MAX);
	length = vec3_length_squared(vec3_sub(point_at(ray, top_t), cy->top));
	if (length > pow(cy->radius, 2.0))
		return (FLOAT_MAX);
	return (top_t);
}

float	is_collided_bottom(t_cylinder *cy, t_ray const *ray, t_coll t)
{
	float	denominator;
	t_vec3	bottom;
	float	bottom_t;
	float	length;

	denominator = vec3_dot(cy->normal, ray->direction);
	if (denominator == 0)
		return (FLOAT_MAX);
	bottom = vec3_sub(cy->bottom, ray->origin);
	bottom_t = vec3_dot(bottom, cy->normal) / denominator;
	if (bottom_t <= t.min || t.max <= bottom_t)
		bottom_t = FLOAT_MAX;
	length = vec3_length_squared(vec3_sub(point_at(ray, bottom_t), cy->bottom));
	if (length > pow(cy->radius, 2.0))
		return (FLOAT_MAX);
	return (bottom_t);
}


