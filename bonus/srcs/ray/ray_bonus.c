/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:54:29 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:51:54 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"
#include "vec3_bonus.h"
#include "minirt_bonus.h"
#include <stdlib.h>
#include <time.h>

t_point3	point_at(t_ray const *ray, float t)
{
	return (vec3_add(ray->origin, vec3_mul(ray->direction, t)));
}

t_vec3	get_pixel_center(t_camera *camera, t_viewport *viewport, int i, int j)
{
	t_vec3	pixel;

	pixel = vec3_add(viewport->pixel00_loc, \
		vec3_mul(viewport->pixel_delta_u, i));
	pixel = vec3_add(pixel, \
		vec3_mul(viewport->pixel_delta_v, j));
	return (vec3_sub(pixel, camera->view_point));
}

t_vec3	get_pixel_random(t_camera *camera, t_viewport *viewport, int i, int j)
{
	t_vec3	offset;
	t_vec3	pixel;

	offset = get_random_offset();
	pixel = vec3_add(viewport->pixel00_loc, \
		vec3_mul(viewport->pixel_delta_u, i + offset.x));
	pixel = vec3_add(pixel, \
		vec3_mul(viewport->pixel_delta_v, j + offset.y));
	return (vec3_sub(pixel, camera->view_point));
}

t_vec3	get_random_offset(void)
{
	t_vec3	offset;

	offset.x = (float)rand() / (float)RAND_MAX;
	offset.y = (float)rand() / (float)RAND_MAX;
	offset.z = 0;
	return (offset);
}