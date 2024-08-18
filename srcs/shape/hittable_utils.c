/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:44:27 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 00:21:17 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/hittable.h"
#include <math.h>

void	set_face_normal(t_record *rec, t_ray const *ray, t_vec3 outward_normal)
{
	rec->front_face = vec3_dot(ray->direction, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = vec3_mul(outward_normal, -1);
}

t_bool	quadratic_equation(t_quadratic var, t_coll t, float *root)
{
	float	discriminant;
	float	sqrtd;

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
