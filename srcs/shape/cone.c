/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:28:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/13 23:48:37 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/cone.h"
#include "error.h"
#include <stdlib.h>

t_cone	*init_cone(t_cone data)
{
	t_cone	*cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	if (!cone)
		error_exit(ERROR_MALLOC);
	cone->parent.shape = CYLINDER;
	cone->parent.hit = hit_cone;
	cone->center = data.center;
	cone->normal = data.normal;
	cone->diameter = data.diameter;
	cone->height = data.height;
	cone->color = data.color;
	return (cone);
}

t_bool	hit_cone(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec)
{
	(void)obj;
	(void)ray;
	(void)t;
	(void)rec;
	return (FALSE);
}
