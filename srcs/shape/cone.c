/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:28:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/14 19:18:18 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/cone.h"
#include "error.h"
#include <stdlib.h>
#include <math.h>

static float	get_theta(t_cone *co);
static t_bool	is_collided(\
	t_cone *co, t_ray const *ray, float *root, t_coll t);

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
	co->theta = get_theta(co);
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

	co = (t_cone *)obj;
	if (!is_collided(co, ray, &root, t))
		return (FALSE);
	rec->t = root;
	rec->p = point_at(ray, rec->t);
	rec->color = co->color;
	rec->normal = co->normal;	// TODO: set normal
	outward_normal = co->normal;	// TODO: set outward_normal
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
	float		discriminant;
	float		sqrtd;
	float		m;
	t_vec3		h;
	t_vec3		w;

	h = vec3_div(vec3_sub(co->top, co->bottom), co->height);
	m = pow(co->radius, 2.0) / pow(co->height, 2.0);
	w = vec3_sub(ray->origin, co->top);
	var.a = vec3_dot(ray->direction, ray->direction) - \
		(m - 1) * pow(vec3_dot(ray->direction, h), 2.0);
	var.b = vec3_dot(ray->direction, w) - \
		(m - 1) * vec3_dot(ray->direction, h) * vec3_dot(w, h);
	var.c = vec3_dot(w, w) - (m - 1) * pow(vec3_dot(w, h), 2.0);
	discriminant = pow(var.b, 2.0) - var.a * var.c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrtf(discriminant);
	*root = (-var.b - sqrtd) / var.a;
	if (*root <= t.min || t.max <= *root)
	{
		*root = (-var.b + sqrtd) / var.a;
		if (*root <= t.min || t.max <= *root)
			return (FALSE);
	}
	return (TRUE);
}
