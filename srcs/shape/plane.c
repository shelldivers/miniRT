/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:41:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/23 02:17:09 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/plane.h"
#include "shape/texture.h"
#include "vec2.h"
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
	plane->parent.color = data.parent.color;
	plane->parent.texture = data.parent.texture;
	if (has_texture_map(data.parent.texture))
	{
		plane->parent.uv_map = get_uv_map_plane;
		plane->parent.uv_color = uv_color_map_adapter(data.parent.texture);
	}
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
	rec->color = plane->parent.color;
	outward_normal = plane->normal;
	set_face_normal(rec, ray, outward_normal);
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

	denominator = vec3_dot(plane->normal, ray->direction);
	if (denominator == 0)
		return (FALSE);
	pn = vec3_sub(plane->center, ray->origin);
	*root = vec3_dot(pn, plane->normal) / denominator;
	if (*root <= t.min || t.max <= *root)
		return (FALSE);
	return (TRUE);
}

t_vec2	get_uv_map_plane(t_hit *obj, t_record *rec)
{
	(void)obj;
	(void)rec;
	return ((t_vec2){0, 0});
}
