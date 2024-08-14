/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:41:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 00:39:46 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/plane.h"
#include "error.h"
#include <stdlib.h>

static t_bool	is_collided(t_plane *p, t_ray const *ray, float *r, t_coll t);

t_plane	*init_plane(t_plane data)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		error_exit(ERROR_MALLOC);
	plane->parent.shape = PLANE;
	plane->parent.hit = hit_plane;
	plane->center = data.center;
	plane->normal = data.normal;
	plane->color = data.color;
	return (plane);
}

/**
 * @brief Check if the ray hits the plane
 * @param obj The plane object
 * @param ray The ray
 * @param t The collision range
 * @param rec The record of the collision
 * @return t_bool TRUE if the ray hits the plane, FALSE otherwise
 */
t_bool	hit_plane(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec)
{
	t_plane	*plane;
	float	root;

	plane = (t_plane *)obj;
	if (!is_collided(plane, ray, &root, t))
		return (FALSE);
	rec->t = root;
	rec->p = point_at(ray, rec->t);
	rec->color = plane->color;
	rec->normal = plane->normal;
	set_face_normal(rec, ray, plane->normal);
	return (TRUE);
}

/**
 * @brief Check if the ray hits the plane
 * @see http://www.illusioncatalyst.com/notes.php
 * @param plane The plane object
 * @param ray The ray
 * @param root The pointer to the root
 * @param t The collision range
 * @return t_bool TRUE if the ray hits the plane, FALSE otherwise
 */
t_bool	is_collided(t_plane *plane, t_ray const *ray, float *root, t_coll t)
{
	t_vec3	pn;
	float	denominator;

	denominator = vec3_dot(plane->normal, ray->direction);
	if (denominator == 0)
		return (FALSE);
	pn = vec3_sub(plane->center, ray->origin);
	*root = vec3_dot(pn, plane->normal) / denominator;
	if (*root <= t.min || t.max <= *root)
		return (FALSE);
	return (TRUE);
}
