/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:37:28 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/21 18:40:48 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/cone.h"
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
	co->color = data.color;
	co->top = vec3_add(co->center, vec3_mul(co->normal, co->height / 2));
	co->bottom = vec3_sub(co->center, vec3_mul(co->normal, co->height / 2));
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
	t_point3	c;
	t_point3	p;
	t_vec3		v;
	t_vec3		cp;
	t_vec3		cc;

	c = co->top;
	p = point_at(ray, surface_t);
	v = vec3_unit(vec3_sub(co->bottom, co->top));
	cp = vec3_sub(p, c);
	rec->t = surface_t;
	rec->p = p;
	rec->color = co->color;
	cc = vec3_mul(v, vec3_length_squared(cp) / vec3_dot(cp, v));
	rec->normal = vec3_sub(cp, cc);
	set_face_normal(rec, ray, rec->normal);
}

void	set_record_endcaps(\
	t_cone *co, t_ray const *ray, t_record *rec, float endcap_t)
{
	rec->t = endcap_t;
	rec->p = point_at(ray, rec->t);
	rec->color = co->color;
	rec->normal = co->normal;
	set_face_normal(rec, ray, co->normal);
}
