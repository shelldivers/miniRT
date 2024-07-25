/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:31 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/25 23:05:51 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "minirt.h"
#include "ray.h"
#include "point3.h"
#include "vec3.h"
#include "color.h"
#include "camera.h"
#include <stdlib.h>

t_color	ray_color(t_ray const *ray)
{
	t_vec3	unit_direction;
	float	a;
	float	t;
	t_vec3	n;

	t = hit_sphere((t_point3){0, 0, -1}, 0.5, ray);
	if (t > 0.0)
	{
		n = vec3_unit(vec3_sub(point_at(ray, t), (t_vec3){0, 0, -1}));
		return vec3_mul((t_color){n.x + 1, n.y + 1, n.z + 1}, 0.5);
	}
	unit_direction = vec3_unit(ray->direction);
	a = 0.5 * (unit_direction.y + 1.0);
	return (vec3_add(vec3_mul((t_color){1.0, 1.0, 1.0}, 1.0 - a), \
		vec3_mul((t_color){0.5, 0.7, 1.0}, a)));
}

t_point3	point_at(t_ray const *ray, float t)
{
	return (vec3_add(ray->origin, vec3_mul(ray->direction, t)));
}

float	hit_sphere(t_point3 center, float radius, t_ray const *ray)
{
	t_vec3	oc;
	float	a;
	float	b;
	float	c;
	float	discriminant;

	oc = vec3_sub(center, ray->origin);
	a = vec3_dot(ray->direction, ray->direction);
	b = -2.0 * vec3_dot(ray->direction, oc);
	c = vec3_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
        return (-1.0);
    return ((-b - sqrt(discriminant) ) / (2.0 * a));
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
