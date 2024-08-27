/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:37:28 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:04:00 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/cone.h"
#include "shape/map.h"
#include "shape/plane.h"
#include "error.h"
#include <stdlib.h>
#include <math.h>

static void	set_record_surface(\
	t_cone *cy, t_ray const *ray, t_record *rec, float surface_t);
static void	set_record_endcaps(\
	t_cone *cy, t_ray const *ray, t_record *rec, float endcap_t);

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
	co->parent.color = data.parent.color;
	co->top = vec3_add(co->center, vec3_mul(co->normal, co->height / 2));
	co->bottom = vec3_sub(co->center, vec3_mul(co->normal, co->height / 2));
	co->parent.texture = data.parent.texture;
	co->parent.uv_map = get_uv_map_cone;
	if (is_texture_map_enabled(data.parent.texture))
		co->parent.uv_color = uv_color_map_adapter(data.parent.texture);
	return (co);
}

t_bool	hit_cone(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec)
{
	t_cone		*co;
	float		surface_t;
	float		endcaps_t;

	co = (t_cone *)obj;
	surface_t = hit_cone_surface(co, ray, t);
	endcaps_t = hit_cone_endcaps(co, ray, t);
	if (surface_t == FLOAT_MAX && endcaps_t == FLOAT_MAX)
		return (FALSE);
	if (surface_t < endcaps_t)
		set_record_surface(co, ray, rec, surface_t);
	else
		set_record_endcaps(co, ray, rec, endcaps_t);
	return (TRUE);
}

/**
 * @todo Check if the normal vector is correct
 */
void	set_record_surface(\
	t_cone *co, t_ray const *ray, t_record *rec, float surface_t)
{
	t_vec3		v;
	t_vec3		cp;
	t_vec3		cc;
	t_vec3		outward_normal;

	rec->t = surface_t;
	rec->p = point_at(ray, surface_t);
	v = vec3_unit(vec3_sub(co->bottom, co->top));
	cp = vec3_sub(rec->p, co->top);
	cc = vec3_mul(v, vec3_length_squared(cp) / vec3_dot(cp, v));
	outward_normal = vec3_unit(vec3_sub(cp, cc));
	set_face_normal(rec, ray, outward_normal);
	rec->obj = (t_hit *)co;
}

void	set_record_endcaps(\
	t_cone *co, t_ray const *ray, t_record *rec, float endcap_t)
{
	t_vec3	outward_normal;

	rec->t = endcap_t;
	rec->p = point_at(ray, rec->t);
	rec->color = co->parent.color;
	outward_normal = co->normal;
	set_face_normal(rec, ray, outward_normal);
	rec->obj = (t_hit *)co;
}

t_vec2	get_uv_map_cone(t_hit *obj, t_record *rec)
{
	t_cone	*co;
	t_vec3	p;
	float	theta;
	t_vec2	uv;
	float	radius;

	co = (t_cone *)obj;
	p = vec3_sub(rec->p, co->center);
	radius = co->radius * (1.0 - (p.y / co->height));
	p.x = p.x / radius;
	p.z = p.z / radius;
	p.y = p.y / co->height;
	theta = atan2(p.x, p.z);
	uv.u = 1 - (theta / (2 * M_PI)) + 0.5;
	uv.v = 1 - fmod(p.y, 1);
	return (uv);
}
