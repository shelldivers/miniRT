/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_endcaps_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:42:02 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:52:26 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "shape/cone_bonus.h"
#include "error_bonus.h"
#include <stdlib.h>
#include <math.h>

float	hit_cone_endcaps(t_cone *co, t_ray const *ray, t_coll t)
{
	t_vec3	pn;
	float	length;
	float	bottom_t;
	float	denominator;

	denominator = vec3_dot(ray->direction, co->normal);
	if (fabs(denominator) < EPSILON)
		return (FLOAT_MAX);
	pn = vec3_sub(co->bottom, ray->origin);
	bottom_t = vec3_dot(pn, co->normal) / denominator;
	if (bottom_t <= t.min || t.max <= bottom_t)
		return (FLOAT_MAX);
	length = vec3_length_squared(vec3_sub(point_at(ray, bottom_t), co->bottom));
	if (length > pow(co->radius, 2.0))
		return (FLOAT_MAX);
	return (bottom_t);
}