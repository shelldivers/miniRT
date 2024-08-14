/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:37:28 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 00:21:18 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/cone.h"
#include "error.h"
#include <stdlib.h>
#include <math.h>

static t_bool	is_collided(\
	t_cone *co, t_ray const *ray, float *root, t_coll t);
static t_bool	is_point_within_cone_bounds(\
	t_cone *co, t_ray const *ray, float root);

t_cone	*init_cone(t_cone data)
{
	t_cone	*co;

	co = (t_cone *)malloc(sizeof(t_cone));
	if (!co)
		error_exit(ERROR_MALLOC);
	co->parent.shape = CYLINDER;
	co->parent.hit = hit_cone;
	co->center = data.center;
	co->normal = data.normal;
	co->radius = data.radius;
	co->height = data.height;
	co->color = data.color;
	co->top = vec3_add(co->center, vec3_mul(co->normal, co->height / 2));
	co->bottom = vec3_sub(co->center, vec3_mul(co->normal, co->height / 2));
	return (co);
}

float	get_theta(t_cone *co)
{
	return (atan(co->radius / co->height));
}

t_bool	hit_cone(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec)
{
	t_cone		*co;
	float		root;
	t_vec3		outward_normal;
	t_vec3		cp;
	float		k;

	co = (t_cone *)obj;
	if (!is_collided(co, ray, &root, t))
		return (FALSE);
	rec->t = root;
	rec->p = point_at(ray, rec->t);
	rec->color = co->color;
	rec->normal = co->normal;	// TODO: set normal
	cp = vec3_sub(rec->p, co->bottom);
	k = vec3_dot(cp, co->normal) / vec3_dot(co->normal, co->normal);
	outward_normal = vec3_unit(vec3_sub(cp, vec3_mul(co->normal, k)));
	set_face_normal(rec, ray, outward_normal);
	return (TRUE);
}

/**
 * @brief Check if the ray hits the cone
 * @see http://www.illusioncatalyst.com/notes_files/mathematics/line_cone_intersection.php
 * @param co	pointer to the cone
 * @param ray	pointer to the ray
 * @param root	pointer to the root
 * @param t		t_coll
 * @return t_bool
 */
t_bool	is_collided(t_cone *co, t_ray const *ray, float *root, t_coll t)
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
	if (!is_point_within_cone_bounds(co, ray, *root))
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
