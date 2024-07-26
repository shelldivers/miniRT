/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:40:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 23:59:53 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_bool.h"
#include "hittable.h"
#include "sphere.h"
#include "vec3.h"
#include <math.h>
#include <stdlib.h>

t_sphere	*init_sphere(t_point3 center, float radius, t_color color)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		error_exit("Memory allocation failed");
	sphere->parent.shape = SPHERE;
	sphere->parent.hit = hit_sphere;
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}

t_bool	hit_sphere(t_hittable *obj, t_ray const *ray, \
	t_collision t, t_hit_record *rec)
{
	t_sphere	*sphere;
	float		root;
	t_vec3		outward_normal;

	sphere = (t_sphere *)obj;
	if (!is_collided(sphere, ray, &root, t))
		return (FALSE);
	rec->t = root;
	rec->p = point_at(ray, rec->t);
	rec->normal = vec3_div(vec3_sub(rec->p, sphere->center), sphere->radius);
	outward_normal = vec3_div(vec3_sub(rec->p, sphere->center), sphere->radius);
	set_face_normal(rec, ray, outward_normal);
	return (TRUE);
}

t_bool	is_collided(t_sphere *sphere, t_ray const *ray, \
	float *root, t_collision t)
{
	float		sqrtd;
	t_vec3		oc;
	float		a;
	float		h;
	float		discriminant;

	oc = vec3_sub(sphere->center, ray->origin);
	a = vec3_length_squred(ray->direction);
	h = vec3_dot(ray->direction, oc);
	discriminant = h * h - a * \
		(vec3_length_squred(oc) - sphere->radius * sphere->radius);
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	*root = (h - sqrtd) / a;
	if (*root <= t.min || t.max <= *root)
	{
		*root = (h + sqrtd) / a;
		if (*root <= t.min || t.max <= *root)
			return (FALSE);
	}
	return (TRUE);
}
