/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:31 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 02:17:10 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include "point3.h"
#include "vec3.h"
#include "color.h"
#include "camera.h"
#include "hittable.h"
#include <stdlib.h>
#include <math.h>

t_point3	point_at(t_ray const *ray, float t)
{
	return (vec3_add(ray->origin, vec3_mul(ray->direction, t)));
}

float	ray_hit_sphere(t_point3 center, float radius, t_ray const *ray)
{
	t_vec3	oc;
	float	a;
	float	h;
	float	c;
	float	discriminant;

	oc = vec3_sub(center, ray->origin);
	a = vec3_length_squred(ray->direction);
	h = vec3_dot(ray->direction, oc);
	c = vec3_length_squred(oc) - radius * radius;
	discriminant = h * h - a * c;
	if (discriminant < 0)
        return (-1.0);
    return ((h - sqrt(discriminant)) / a);
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
