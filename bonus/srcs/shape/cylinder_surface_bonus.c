/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_surface_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:38:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:52:43 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "shape/cylinder_bonus.h"
#include <math.h>

static t_bool	is_collided_surface(\
	t_cylinder *cy, t_ray const *ray, t_coll t, float *root);
static t_bool	is_point_within_cylinder_bounds(\
	t_cylinder *cy, t_ray const *ray, float root);

/**
 * @brief Check if the ray hits the cylinder surface
 * @param cy	pointer to the cylinder
 * @param ray	pointer to the ray
 * @param t		t_coll
 * @return float
 */
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
 * @brief collision detection with the cylinder surface
 * @param cy	pointer to the cylinder
 * @param ray	pointer to the ray
 * @param t		t_coll
 * @param root	pointer to the root
 * @return t_bool
 * @see http://www.illusioncatalyst.com/notes.php
 */
t_bool	is_collided_surface(\
	t_cylinder *cy, t_ray const *ray, t_coll t, float *root)
{
	t_quadratic	var;

	var.v = ray->direction;
	var.h = cy->normal;
	var.w = vec3_sub(ray->origin, cy->center);
	var.a = vec3_dot(var.v, var.v) - pow(vec3_dot(var.v, var.h), 2.0);
	if (var.a == 0)
		return (FALSE);
	var.b = vec3_dot(var.v, var.w) \
		- vec3_dot(var.v, var.h) * vec3_dot(var.w, var.h);
	var.c = vec3_dot(var.w, var.w) \
		- pow(vec3_dot(var.w, var.h), 2.0) - pow(cy->radius, 2.0);
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
