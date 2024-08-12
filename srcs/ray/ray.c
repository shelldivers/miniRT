/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:54:29 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/03 00:01:06 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"
#include "minirt.h"

t_point3	point_at(t_ray const *ray, float t)
{
	return (vec3_add(ray->origin, vec3_mul(ray->direction, t)));
}

t_vec3	get_direction(t_camera *camera, t_viewport *viewport, int i, int j)
{
	t_vec3	pixel_center;

	pixel_center = vec3_add(viewport->pixel00_loc, \
		vec3_mul(viewport->pixel_delta_u, i));
	pixel_center = vec3_add(pixel_center, \
		vec3_mul(viewport->pixel_delta_v, j));
	return (vec3_sub(pixel_center, camera->view_point));
}
