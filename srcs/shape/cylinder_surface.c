/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_surface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:38:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 00:39:25 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/cylinder.h"
#include <math.h>

static t_bool	is_collided_surface(\
	t_cylinder *cy, t_ray const *ray, t_coll t, float *root);
static t_bool	is_point_within_cylinder_bounds(\
	t_cylinder *cy, t_ray const *ray, float root);

float	hit_cylinder_surface(t_cylinder *cy, t_ray const *ray, t_coll t)
{
	float		root;

	if (!is_collided_surface(cy, ray, t, &root))
		return (FLOAT_MAX);
	if (!is_point_within_cylinder_bounds(cy, ray, root))
		return (FLOAT_MAX);
	return (root);
}

/**
 * @brief Check if the ray hits the cylinder
 * @see http://www.illusioncatalyst.com/notes.php
 * @param cy	pointer to the cylinder
 * @param ray	pointer to the ray
 * @param t		t_coll
 * @param rec	pointer to the record
 * @return t_bool
 */
t_bool	is_collided_surface(\
	t_cylinder *cy, t_ray const *ray, t_coll t, float *root)
{
	t_quadratic	var;

	var.oc = vec3_sub(ray->origin, cy->center);
	var.u = vec3_cross(ray->direction, cy->normal);
	var.v = vec3_cross(var.oc, cy->normal);
	var.a = vec3_length_squared(var.u);
	if (var.a == 0)
		return (FALSE);
	var.b = vec3_dot(var.u, var.v);
	var.c = vec3_length_squared(var.v) - pow(cy->radius, 2.0);
	if (!quadratic_equation(var, t, root))
		return (FALSE);
	return (TRUE);
}

t_bool	is_point_within_cylinder_bounds(\
	t_cylinder *cy, t_ray const *ray, float root)
{
	t_vec3	pointed_at;
	float	top_dot;
	float	bottom_dot;

	pointed_at = point_at(ray, root);
	top_dot = vec3_dot(vec3_sub(pointed_at, cy->top), cy->normal);
	bottom_dot = vec3_dot(vec3_sub(pointed_at, cy->bottom), cy->normal);
	if (top_dot > 0 || bottom_dot < 0)
		return (FALSE);
	return (TRUE);
}
