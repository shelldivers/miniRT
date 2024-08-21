/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:28:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 01:04:14 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include "shape/cylinder.h"
#include <stdlib.h>
#include <math.h>

void	set_record_surface(\
	t_cylinder *cy, t_ray const *ray, t_record *rec, float surface_t);
void	set_record_endcaps(\
	t_cylinder *cy, t_ray const *ray, t_record *rec, float endcap_t);

t_cylinder	*init_cylinder(t_cylinder data)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		error_exit(ERROR_MALLOC);
	cy->parent.shape = CYLINDER;
	cy->parent.hit = hit_cylinder;
	cy->center = data.center;
	cy->normal = data.normal;
	cy->radius = data.radius;
	cy->height = data.height;
	cy->color = data.color;
	cy->top = vec3_add(cy->center, vec3_mul(cy->normal, cy->height / 2));
	cy->bottom = vec3_sub(cy->center, vec3_mul(cy->normal, cy->height / 2));
	return (cy);
}

t_bool	hit_cylinder(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec)
{
	t_cylinder	*cy;
	float		surface_t;
	float		endcaps_t;

	cy = (t_cylinder *)obj;
	surface_t = hit_cylinder_surface(cy, ray, t);
	endcaps_t = hit_cylinder_endcaps(cy, ray, t);
	if (surface_t == FLOAT_MAX && endcaps_t == FLOAT_MAX)
		return (FALSE);
	if (surface_t < endcaps_t)
		set_record_surface(cy, ray, rec, surface_t);
	else
		set_record_endcaps(cy, ray, rec, endcaps_t);
	return (TRUE);
}

/**
 * @todo Check if the normal vector is correct
 */
void	set_record_surface(\
	t_cylinder *cy, t_ray const *ray, t_record *rec, float surface_t)
{
	t_vec3	proj;

	rec->t = surface_t;
	rec->p = point_at(ray, rec->t);
	rec->color = cy->color;
	proj = vec3_mul(cy->normal, \
		vec3_dot(vec3_sub(rec->p, cy->bottom), cy->normal));
	rec->normal = vec3_unit(vec3_sub(vec3_sub(rec->p, cy->bottom), proj));
	set_face_normal(rec, ray, rec->normal);
}

void	set_record_endcaps(\
	t_cylinder *cy, t_ray const *ray, t_record *rec, float endcap_t)
{
	rec->t = endcap_t;
	rec->p = point_at(ray, rec->t);
	rec->color = cy->color;
	rec->normal = cy->normal;
	set_face_normal(rec, ray, cy->normal);
}
