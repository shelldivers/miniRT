/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:09:37 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/22 15:47:56 by jiwojung         ###   ########.fr       */
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
	t_color	light_color;
	t_vec3	to_light_u;
	float	cos_alpha;
	t_color	luminance;

	light_color = vec3_mul(light->color, light->ratio);
	to_light_u = vec3_unit(vec3_sub(light->center, rec->p));
	cos_alpha = vec3_dot(rec->normal, to_light_u);
	if (cos_alpha < 0)
		cos_alpha = 0;
	luminance = vec3_mul(light_color, cos_alpha);
	return (vec3_mul(luminance, DIFFUSE_CONST));
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
	t_vec3	view_u;
	t_vec3	from_light_u;
	float	cos_alpha;
	t_color	luminance;

	from_light_u = vec3_unit(vec3_sub(rec->p, light->center));
	ray_reflect = vec3_sub(from_light_u, \
		vec3_mul(rec->normal, 2 * vec3_dot(from_light_u, rec->normal)));
	view_u = vec3_unit(vec3_sub(cam->view_point, rec->p));
	cos_alpha = vec3_dot(ray_reflect, view_u);
	if (cos_alpha < 0)
		cos_alpha = 0;
	cos_alpha = pow(cos_alpha, SHININESS_CONST);
	luminance = vec3_mul(light->color, cos_alpha);
	return (vec3_mul(luminance, SPECULAR_CONST));
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
	t_vec3		to_light;
	t_vec3		ray_origin;
	t_ray		ray;

	to_light = vec3_sub(light->center, rec->p);
	ray_origin = vec3_add(rec->p, vec3_mul(to_light, 0.0001));
	ray = (t_ray){ray_origin, to_light};
	if (hit_shapes(world, &ray, (t_coll){0.0, FLOAT_MAX}, NULL))
		return (TRUE);
	return (FALSE);
}
