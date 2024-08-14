/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_endcaps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:42:02 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 00:51:54 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape/cone.h"
#include "error.h"
#include <stdlib.h>
#include <math.h>

static t_bool	is_collided_bottom(\
	t_cone *co, t_ray const *ray, t_coll t, float *root);

float	hit_cone_endcaps(t_cone *co, t_ray const *ray, t_coll t)
{
	float	root;

	if (!is_collided_bottom(co, ray, t, &root))
		return (FLOAT_MAX);
	return (FLOAT_MAX);
}

t_bool	is_collided_bottom(t_cone *co, t_ray const *ray, t_coll t, float *root)
{
	t_vec3	pn;
	float	length;
	float	denominator;

	denominator = vec3_dot(ray->direction, co->normal);
	if (fabs(denominator) < 0)
		return (FALSE);
	pn = vec3_sub(co->bottom, ray->origin);
	length = vec3_dot(pn, co->normal) / denominator;
	if (length < 0 || length > t.max)
		return (FALSE);
	*root = length;
	return (TRUE);
}
