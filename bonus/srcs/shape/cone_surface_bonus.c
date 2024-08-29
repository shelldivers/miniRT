/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_surface_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:37:28 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:52:30 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "shape/cone_bonus.h"
#include "error_bonus.h"
#include <stdlib.h>
#include <math.h>

static t_bool	is_collided_surface(\
	t_cone *co, t_ray const *ray, float *root, t_coll t);
static t_bool	is_point_within_cone_bounds(\
	t_cone *co, t_ray const *ray, float root);

/**
 * @brief Check if the ray hits the cone surface
 * @param co	pointer to the cone
 * @param ray	pointer to the ray
 * @param t		t_coll
 * @return float
 */
float	hit_cone_surface(t_cone *co, t_ray const *ray, t_coll t)
{
	float		root;

	if (!is_collided_surface(co, ray, &root, t))
		return (FLOAT_MAX);
	if (!is_point_within_cone_bounds(co, ray, root))
		return (FLOAT_MAX);
	return (root);
}

/**
 * @brief collision detection with the cone surface
 * @param co	pointer to the cone
 * @param ray	pointer to the ray
 * @param t		t_coll
 * @param root	pointer to the root
 * @return t_bool
 * @see http://www.illusioncatalyst.com/notes.php
 */
t_bool	is_collided_surface(t_cone *co, t_ray const *ray, float *root, t_coll t)
{
	t_quadratic	var;
	float		m;

	var.v = ray->direction;
	var.h = co->normal;
	var.w = vec3_sub(ray->origin, co->top);
	m = pow(co->radius, 2.0) / pow(co->height, 2.0);
	var.a = vec3_dot(var.v, var.v) \
		- (m + 1) * pow(vec3_dot(var.v, var.h), 2.0);
	if (var.a == 0)
		return (FALSE);
	var.b = vec3_dot(var.v, var.w) - (m + 1) \
		* vec3_dot(var.v, var.h) * vec3_dot(var.w, var.h);
	var.c = vec3_dot(var.w, var.w) - (m + 1) * pow(vec3_dot(var.w, var.h), 2.0);
	if (!quadratic_equation(var, t, root))
		return (FALSE);
	return (TRUE);
}

t_bool	is_point_within_cone_bounds(t_cone *co, t_ray const *ray, float root)
{
	t_vec3	pointed_at;
	float	top_dot;
	float	bottom_dot;

	pointed_at = point_at(ray, root);
	top_dot = vec3_dot(vec3_sub(pointed_at, co->top), co->normal);
	bottom_dot = vec3_dot(vec3_sub(pointed_at, co->bottom), co->normal);
	if (top_dot > 0 || bottom_dot < 0)
		return (FALSE);
	return (TRUE);
}