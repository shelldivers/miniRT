/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:28:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 22:42:53 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/cylinder.h"
#include "error.h"
#include <stdlib.h>

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
	cylinder->diameter = data.diameter;
	cylinder->height = data.height;
	cylinder->color = data.color;
	return (cylinder);
}

t_bool	hit_cylinder(t_hit *obj, t_ray const *ray, t_coll t, t_rec *rec)
{
	(void)obj;
	(void)ray;
	(void)t;
	(void)rec;
	return (TRUE);
}
