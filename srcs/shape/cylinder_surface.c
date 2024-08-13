/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_surface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:38:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/14 01:44:48 by jeongwpa         ###   ########.fr       */
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

	if (!is_collided_surface(cy, ray, t, &root))
		return (FLOAT_MAX);
	return (root);
}

t_bool	is_collided_surface(\
	t_cylinder *cy, t_ray const *ray, t_coll t, float *root)
{
	t_quadratic	var;
	float		discriminant;
	float		sqrtd;
	t_vec3		ip;
	float		hit_height;

	var.oc = vec3_sub(ray->origin, cy->center);
	var.u = vec3_cross(ray->direction, cy->normal);
	var.v = vec3_cross(var.oc, cy->normal);
	var.a = vec3_length_squared(var.u);
	var.b = vec3_dot(var.u, var.v);
	var.c = vec3_length_squared(var.v) - pow(cy->radius, 2.0);
	discriminant = pow(var.b, 2.0) - var.a * var.c;
	if (discriminant < 1e-6)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	*root = (-var.b - sqrtd) / var.a;
	if (*root <= t.min || t.max <= *root)
	{
		*root = (-var.b + sqrtd) / var.a;
		if (*root <= t.min || t.max <= *root)
			return (FALSE);
	}
	ip = point_at(ray, *root);
	hit_height = vec3_dot(cy->normal, vec3_sub(ip, cy->center));
	if (hit_height < 0 || hit_height > cy->height)
		return (FALSE);
	return (TRUE);
}
