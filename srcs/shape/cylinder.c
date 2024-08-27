/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:28:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 13:21:18 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec2.h"
#include "error.h"
#include "shape/cylinder.h"
#include "shape/plane.h"
#include "shape/texture.h"
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
	cy->parent.color = data.parent.color;
	cy->top = vec3_add(cy->center, vec3_mul(cy->normal, cy->height / 2));
	cy->bottom = vec3_sub(cy->center, vec3_mul(cy->normal, cy->height / 2));
	cy->parent.texture = data.parent.texture;
	cy->parent.uv_map = get_uv_map_cylinder;
	if (is_texture_map_enabled(data.parent.texture))
		cy->parent.uv_color = uv_color_map_adapter(data.parent.texture);
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
	t_vec3	cp;
	t_vec3	v;
	t_vec3	outward_normal;

	rec->t = surface_t;
	rec->p = point_at(ray, rec->t);
	cp = vec3_sub(rec->p, cy->center);
	v = vec3_unit(vec3_sub(cy->bottom, cy->top));
	outward_normal = vec3_unit(vec3_sub(cp, vec3_mul(v, vec3_dot(cp, v))));
	set_face_normal(rec, ray, outward_normal);
	rec->obj = (t_hit *)cy;
}

void	set_record_endcaps(\
	t_cylinder *cy, t_ray const *ray, t_record *rec, float endcap_t)
{
	t_vec3	outward_normal;

	rec->t = endcap_t;
	rec->p = point_at(ray, rec->t);
	outward_normal = cy->normal;
	set_face_normal(rec, ray, outward_normal);
	rec->obj = (t_hit *)cy;
}

t_vec2	get_uv_map_cylinder(t_hit *obj, t_record *rec)
{
	t_cylinder	*cy;
	t_vec3		p;
	float		theta;
	t_vec2		uv;

	cy = (t_cylinder *)obj;
	p = vec3_sub(rec->p, cy->center);
	p.x = p.x / cy->radius;
	p.z = p.z / cy->radius;
	p.y = p.y / cy->height;
	theta = atan2(p.x, p.z);
	uv.u = 1 - (theta / (2 * M_PI)) + 0.5;
	uv.v = fmod(p.y, 1);
	if (uv.v < 0)
		uv.v += 1;
	return (uv);
}
