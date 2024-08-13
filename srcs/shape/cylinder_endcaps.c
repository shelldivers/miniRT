/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_endcaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:39:29 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/14 03:01:02 by jeongwpa         ###   ########.fr       */
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
	if (top_t < bottom_t)
		*root = top_t;
	else
		*root = bottom_t;
	return (TRUE);
}

float	is_collided_top(t_cylinder *cy, t_ray const *ray, t_coll t)
{
	float	p;
	float	n;
	float	top_t;
	float	length;
	float	denominator;

	denominator = vec3_dot(ray->direction, cy->normal);
	if (fabs(denominator) < FLOAT_EPSILON)
		return (FLOAT_MAX);
	p = vec3_dot(cy->top, cy->normal);
	n = vec3_dot(ray->origin, cy->normal);
	top_t = (p - n) / denominator;
	if (top_t <= t.min || t.max <= top_t)
		return (FLOAT_MAX);
	length = vec3_length_squared(vec3_sub(point_at(ray, top_t), cy->top));
	if (length > pow(cy->radius, 2.0))
		return (FLOAT_MAX);
	return (top_t);
}

float	is_collided_bottom(t_cylinder *cy, t_ray const *ray, t_coll t)
{
	float	p;
	float	n;
	float	length;
	float	bottom_t;
	float	denominator;

	denominator = vec3_dot(cy->normal, ray->direction);
	if (fabs(denominator) < FLOAT_EPSILON)
		return (FLOAT_MAX);
	p = vec3_dot(cy->bottom, cy->normal);
	n = vec3_dot(ray->origin, cy->normal);
	bottom_t = (p - n) / denominator;
	if (bottom_t <= t.min || t.max <= bottom_t)
		return (FLOAT_MAX);
	length = vec3_length_squared(vec3_sub(point_at(ray, bottom_t), cy->bottom));
	if (length > pow(cy->radius, 2.0))
		return (FLOAT_MAX);
	return (bottom_t);
}


