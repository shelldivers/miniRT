/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:13:09 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/22 01:02:11 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"

t_vec3	point3_to_vec3(t_point3 point)
{
	t_vec3	vec;

	vec.x = point.x;
	vec.y = point.y;
	vec.z = point.z;
	return (vec);
}

t_point3	vec3_to_point3(t_vec3 vec)
{
	t_point3	point;

	point.x = vec.x;
	point.y = vec.y;
	point.z = vec.z;
	return (point);
}
