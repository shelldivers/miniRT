/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:54:29 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 18:06:02 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "ray.h"
#include "shape/hittable.h"
#include "reflection.h"
#include "minirt.h"

t_color	ray_color(t_ray const *ray, t_hit_lst *world)
{
	t_vec3	direction;
	float	a;
	t_rec	rec;

	if (hit_shapes(world, ray, (t_coll){0.0, FLOAT_MAX}, &rec))
	{
		direction = random_on_hemisphere(rec.normal);
		return (vec3_mul(ray_color(&(t_ray){rec.p, direction}, world), 0.5));

		// return (get_ambient_light(phong.ambient));
		// return (vec3_mul(vec3_add(rec.normal, (t_color){1.0, 1.0, 1.0}), 0.5));
	}
	// shoot ray to the sky
	direction = vec3_unit(ray->direction);
	a = 0.5 * (direction.y + 1.0);
	// return (vec3_add(vec3_mul((t_color){1.0, 1.0, 1.0}, 1.0 - a), \
	// 	vec3_mul((t_color){0.5, 0.7, 1.0}, a)));
	return ((t_color){255, 255, 255});
}
