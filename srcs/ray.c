/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:31 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 17:28:33 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"

t_point3	point_at(t_ray *ray, float t)
{
	t_point3	point;
	t_vec3		tmp;

	tmp = vec3_add(point3_to_vec3(ray->origin), vec3_mul(ray->direction, t));
	point = point3(tmp.x, tmp.y, tmp.z);
	return (point);
}
