/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_surface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:38:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/14 02:49:10 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/cylinder.h"
#include <math.h>

static t_bool	is_collided_surface(\
	t_cylinder *cy, t_ray const *ray, t_coll t, float *root);

float	hit_cylinder_surface(t_cylinder *cy, t_ray const *ray, t_coll t)
{
	float		root;
	t_vec3		pointed_at;
	float		top_dot;
	float		bottom_dot;

	if (!is_collided_surface(cy, ray, t, &root))
		return (FLOAT_MAX);
	pointed_at = point_at(ray, root);
	top_dot = vec3_dot(cy->normal, vec3_sub(pointed_at, cy->top));
	bottom_dot = vec3_dot(cy->normal, vec3_sub(pointed_at, cy->bottom));
	if (top_dot > FLOAT_EPSILON || bottom_dot < -FLOAT_EPSILON)
		return (FLOAT_MAX);
	return (root);
}

t_bool	is_collided_surface(\
	t_cylinder *cy, t_ray const *ray, t_coll t, float *root)
{
	t_quadratic	var;
	float		discriminant;
	float		sqrtd;

	var.oc = vec3_sub(ray->origin, cy->center);
	var.u = vec3_cross(ray->direction, cy->normal);
	var.v = vec3_cross(var.oc, cy->normal);
	var.a = vec3_length_squared(var.u);
	if (var.a < FLOAT_EPSILON)
		return (FALSE);
	var.b = vec3_dot(var.u, var.v);
	var.c = vec3_length_squared(var.v) - pow(cy->radius, 2.0);
	discriminant = pow(var.b, 2.0) - var.a * var.c;
	if (discriminant < FLOAT_EPSILON)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	*root = (-var.b - sqrtd) / var.a;
	if (*root <= t.min || t.max <= *root)
	{
		*root = (-var.b + sqrtd) / var.a;
		if (*root <= t.min || t.max <= *root)
			return (FALSE);
	}
	return (TRUE);
}
