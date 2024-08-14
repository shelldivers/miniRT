/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_surface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:37:28 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 01:19:21 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/cone.h"
#include "error.h"
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
	t_vec3		w;

	m = pow(co->radius, 2.0) / pow(co->height, 2.0);
	w = vec3_sub(ray->origin, co->top);
	var.a = vec3_dot(ray->direction, ray->direction) \
		- (m + 1) * pow(vec3_dot(ray->direction, co->normal), 2.0);
	if (var.a == 0)
		return (FALSE);
	var.b = vec3_dot(ray->direction, w) - (m + 1) \
		* vec3_dot(ray->direction, co->normal) * vec3_dot(w, co->normal);
	var.c = vec3_dot(w, w) - (m + 1) * pow(vec3_dot(w, co->normal), 2.0);
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
