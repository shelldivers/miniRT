/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:28:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/14 01:20:57 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/cylinder.h"
#include "error.h"
#include <stdlib.h>
#include <math.h>

t_cylinder	*init_cylinder(t_cylinder data)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		error_exit(ERROR_MALLOC);
	cylinder->parent.shape = CYLINDER;
	cylinder->parent.hit = hit_cylinder;
	cylinder->center = data.center;
	cylinder->normal = data.normal;
	cylinder->radius = data.radius;
	cylinder->height = data.height;
	cylinder->color = data.color;
	return (cylinder);
}

t_bool	hit_cylinder(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec)
{
	t_bool		result;
	t_cylinder	*cy;

	cy = (t_cylinder *)obj;
	cy->top = vec3_add(cy->center, vec3_mul(cy->normal, cy->height / 2));
	cy->bottom = vec3_sub(cy->center, vec3_mul(cy->normal, cy->height / 2));
	result = FALSE;
	result |= hit_cylinder_surface(cy, ray, t, rec);
	result |= hit_cylinder_endcaps(cy, ray, t, rec);
	return (result);
}
