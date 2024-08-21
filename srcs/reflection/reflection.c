/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:09:37 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/21 17:00:41 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "vec3.h"
#include "shape/hittable.h"
#include "reflection.h"
#include "minirt.h"

/**
 * @brief get diffused reflection's luminance
 * @param rec	shape info
 * @param light	light info
 * @return t_color luminance with light color
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

/**
 * @brief get specular reflection's luminance
 * @param rec 		shape info
 * @param light 	light info
 * @param cam 		camera info
 * @return t_color
 */
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

/**
 * @brief get specular reflection's luminance
 * @param lights 	light info
 * @param rec 		shape info
 * @param world 	for check blocking light by other shapes
 * @return t_color
 */
t_bool	is_shadowed(t_light *light, t_record *rec, t_hit_lst *world)
{
	t_vec3		to_light_dir;
	t_vec3		ray_origin;
	t_ray		ray;

	to_light_dir = vec3_sub(light->center, rec->p);
	ray_origin = vec3_add(rec->p, vec3_mul(to_light_dir, 0.001));
	ray = (t_ray){ray_origin, to_light_dir};
	if (hit_shapes(world, &ray, (t_coll){0.0, FLOAT_MAX}, NULL))
		return (TRUE);
	return (FALSE);
}
