/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:31 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/06/26 19:14:53 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"

t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = point3(orig.pos.x, orig.pos.y, orig.pos.z);
	ray.dir = vec3(dir.x, dir.y, dir.z);
	return (ray);
}

t_point3	point_at(t_ray *ray, double t)
{
	t_point3	point;
	t_vec3		tmp;

	tmp = vec3_add(ray->orig.pos, vec3_mul(ray->dir, t));
	point = point3(tmp.x, tmp.y, tmp.z);
	return (point);
}
