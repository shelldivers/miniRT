/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:41:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/10 21:40:31 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/plane.h"
#include "error.h"
#include <stdlib.h>

t_plane	*init_plane(t_plane data)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		error_exit(ERROR_MALLOC);
	plane->parent.shape = PLANE;
	plane->parent.hit = hit_plane;
	plane->center = data.center;
	plane->normal = data.normal;
	plane->color = data.color;
	return (plane);
}

t_bool	hit_plane(t_hit *obj, t_ray const *ray, t_coll t, t_rec *rec)
{
	(void)obj;
	(void)ray;
	(void)t;
	(void)rec;
	return (FALSE);
}
