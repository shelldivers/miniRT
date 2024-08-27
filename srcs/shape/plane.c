/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:41:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:04:00 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/plane.h"
#include "shape/map.h"
#include "vec2.h"
#include "error.h"
#include <stdlib.h>
#include <math.h>

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
	plane->parent.color = data.parent.color;
	plane->parent.texture = data.parent.texture;
	plane->parent.uv_map = get_uv_map_plane;
	if (is_texture_map_enabled(data.parent.texture))
		plane->parent.uv_color = uv_color_map_adapter(data.parent.texture);
	return (plane);
}

/**
 * @brief Check if the ray hits the plane\
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
	t_vec3	outward_normal;

	plane = (t_plane *)obj;
	if (!is_collided(plane, ray, &root, t))
		return (FALSE);
	rec->t = root;
	rec->p = point_at(ray, rec->t);
	outward_normal = plane->normal;
	set_face_normal(rec, ray, outward_normal);
	rec->obj = obj;
	return (TRUE);
}

/**
 * @brief collision detection between the plane and the ray
 * @param plane The plane object
 * @param ray The ray
 * @param root The pointer to the root
 * @param t The collision range
 * @return t_bool TRUE if the ray hits the plane, FALSE otherwise
 * @see http://www.illusioncatalyst.com/notes.php
 */
t_bool	is_collided(t_plane *plane, t_ray const *ray, float *root, t_coll t)
{
	t_vec3	pn;
	float	denominator;

	denominator = vec3_dot(ray->direction, plane->normal);
	if (fabs(denominator) < EPSILON)
		return (FALSE);
	pn = vec3_sub(plane->center, ray->origin);
	*root = vec3_dot(pn, plane->normal) / denominator;
	if (*root <= t.min || t.max <= *root)
		return (FALSE);
	return (TRUE);
}

t_vec2	get_uv_map_plane(t_hit *obj, t_record *rec)
{
	t_vec2	uv;

	(void)obj;
	uv.u = fmod(rec->p.x, 1);
	if (uv.u < 0)
		uv.u += 1;
	uv.v = fmod(rec->p.z, 1);
	if (uv.v < 0)
		uv.v += 1;
	return (uv);
}
