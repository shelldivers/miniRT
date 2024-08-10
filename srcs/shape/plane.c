/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:41:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/10 23:53:36 by jeongwpa         ###   ########.fr       */
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

t_bool	hit_plane(t_hit *obj, t_ray const *ray, t_coll t, t_rec *rec)
{
	t_plane	*plane;
	float	root;

	plane = (t_plane *)obj;
	if (!is_collided(plane, ray, &root, t))
		return (FALSE);
	rec->t = root;
	rec->p = point_at(ray, rec->t);
	rec->normal = plane->normal;
	set_face_normal(rec, ray, plane->normal);
	return (FALSE);
}

t_bool	is_collided(t_plane *plane, t_ray const *ray, float *root, t_coll t)
{
	float	p;
	float	n;
	float	denominator;

	denominator = vec3_dot(plane->normal, ray->direction);
	if (denominator == 0)
		return (FALSE);
	p = vec3_dot(plane->normal, plane->center);
	n = vec3_dot(plane->normal, ray->origin);
	*root = (p - n) / denominator;
	if (*root <= t.min || t.max <= *root)
		return (FALSE);
	return (TRUE);
}
