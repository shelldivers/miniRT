/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:36:41 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 01:22:23 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "minirt.h"
#include "shape/sphere.h"
#include <math.h>
#include <stdlib.h>

static t_bool	is_collided(t_sphere *s, t_ray const *ray, float *r, t_coll t);

t_sphere	*init_sphere(t_sphere data)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		error_exit("Memory allocation failed");
	sphere->parent.shape = SPHERE;
	sphere->parent.hit = hit_sphere;
	sphere->center = data.center;
	sphere->radius = data.radius;
	sphere->color = data.color;
	return (sphere);
}

/**
 * @brief Check if the ray hits the sphere
 * @param obj The sphere object
 * @param ray The ray
 * @param t The collision range
 * @param rec The record of the collision
 * @return t_bool TRUE if the ray hits the sphere, FALSE otherwise
 */
t_bool	hit_sphere(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec)
{
	t_sphere	*sphere;
	float		root;
	t_vec3		outward_normal;

	sphere = (t_sphere *)obj;
	if (!is_collided(sphere, ray, &root, t))
		return (FALSE);
	rec->t = root;
	rec->p = point_at(ray, rec->t);
	rec->color = sphere->color;
	rec->normal = vec3_div(vec3_sub(rec->p, sphere->center), sphere->radius);
	outward_normal = vec3_div(vec3_sub(rec->p, sphere->center), sphere->radius);
	set_face_normal(rec, ray, outward_normal);
	return (TRUE);
}

/**
 * @brief Check if the ray hits the sphere
 * @see http://www.illusioncatalyst.com/notes.php
 * @param sphere The sphere object
 * @param ray The ray
 * @param root The root of the equation
 * @param t The collision range
 * @return t_bool TRUE if the ray hits the sphere, FALSE otherwise
 */
t_bool	is_collided(t_sphere *sphere, t_ray const *ray, float *root, t_coll t)
{
	t_quadratic	var;

	var.oc = vec3_sub(ray->origin, sphere->center);
	var.a = vec3_length_squared(ray->direction);
	if (var.a == 0)
		return (FALSE);
	var.b = vec3_dot(ray->direction, var.oc);
	var.c = vec3_length_squared(var.oc) - sphere->radius * sphere->radius;
	if (!quadratic_equation(var, t, root))
		return (FALSE);
	return (TRUE);
}
