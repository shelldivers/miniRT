/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:09:37 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/20 20:49:25 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec3.h"
#include "shape/hittable.h"
#include "reflection.h"

/**
 * @brief get diffused color
 * @param t_vec3 normal
 * @param t_vec3 light_dir
 * @param t_color light_color
 * @implements luminance * light_color is diffused pixel color
 * @bug don't know but something is wrong
 * @return t_color
 */
t_color	get_diffused_luminance(t_record *rec, t_light *light)
{
	t_color	luminance;
	t_vec3	to_light_dir;
	float	cos_alpha;

	to_light_dir = vec3_sub(light->center, rec->p);
	cos_alpha = vec3_dot(vec3_unit(rec->normal), vec3_unit(to_light_dir));
	if (cos_alpha < 0)
		cos_alpha = 0;
	luminance = vec3_mul(light->color, cos_alpha);
	return (luminance);
}

t_color	get_specular_luminance(t_record *rec, t_light *light, t_camera *cam)
{
	t_vec3	ray_reflect;
	t_vec3	view_dir;
	t_vec3	from_light_dir;
	float	spec;

	from_light_dir = vec3_sub(rec->p, light->center);
	ray_reflect = vec3_sub(from_light_dir, \
		vec3_mul(rec->normal, 2 * vec3_dot(from_light_dir, rec->normal)));
	view_dir = vec3_sub(cam->view_point, rec->p);
	spec = vec3_dot(vec3_unit(ray_reflect), vec3_unit(view_dir));
	if (spec < 0)
		spec = 0;
	spec = pow(spec, 128);
	return (vec3_mul(vec3_mul(light->color, spec), 0.5));
}

// t_vec3	random_in_unit_sphere(void)
// {
// 	t_vec3	p;

// 	while (1)
// 	{
// 		p = vec3_random_range(-1, 1);
// 		if (vec3_length_squred(p) >= 1)
// 			break ;
// 	}
// 	return (p);
// }

// t_vec3	random_unit_vector(void)
// {
// 	return (vec3_unit(random_in_unit_sphere()));
// }

// t_vec3	random_on_hemisphere(t_vec3 normal)
// {
// 	t_vec3	in_unit_sphere;

// 	in_unit_sphere = random_unit_vector();
// 	if (vec3_dot(in_unit_sphere, normal) > 0.0)
// 		return (in_unit_sphere);
// 	else
// 		return (vec3_mul(in_unit_sphere, -1));
// }
