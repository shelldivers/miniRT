/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:31 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/23 18:43:52 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"
#include "color.h"

t_color	get_color(t_ray const *ray)
{
	t_vec3	unit_direction;
	float	a;
	t_vec3	color1;
	t_vec3	color2;

	if (hit_sphere(point3(0, 0, -1), 0.5, ray))
	{
		return (color(1, 0, 0));
	}
	unit_direction = vec3_unit(ray->direction);
	a = 0.5 * (unit_direction.y + 1.0);
	color1 = vec3_mul(color(1.0, 1.0, 1.0), 1.0 - a);
	color2 = vec3_mul(color(0.5, 0.7, 1.0), a);
	return (vec3_add(color1, color2));
}

t_point3	point_at(t_ray *ray, float t)
{
	t_point3	point;
	t_vec3		tmp;

	tmp = vec3_add(ray->origin, vec3_mul(ray->direction, t));
	point = point3(tmp.x, tmp.y, tmp.z);
	return (point);
}

bool	hit_sphere(t_point3 center, float radius, t_ray const *ray)
{
	t_vec3	oc;
	float	a;
	float	b;
	float	c;

	oc = vec3_sub(center, ray->origin);
	a = vec3_dot(ray->direction, ray->direction);
	b = vec3_dot(ray->direction, oc) * -2.0;
	c = vec3_dot(oc, oc) - radius * radius;
	return (b * b - 4 * a * c >= 0);
}
