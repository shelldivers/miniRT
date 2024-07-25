/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:11:26 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 02:07:45 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"
#include "ray.h"
#include "vec3.h"

/**
 * Sets the hit record normal vector.
 * NOTE: the parameter `outward_normal` is assumed to have unit length.
 */
void    set_face_normal(t_hit_record *rec, t_ray const *ray, t_vec3 outward_normal) {
	rec->front_face = vec3_dot(ray->direction, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = vec3_mul(outward_normal, -1);
}
