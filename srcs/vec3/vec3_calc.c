/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:30:25 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 17:11:10 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	return (vec);
}

t_vec3	vec3_sub(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	return (vec);
}

t_vec3	vec3_mul(t_vec3 vec1, float t)
{
	t_vec3	vec;

	vec.x = vec1.x * t;
	vec.y = vec1.y * t;
	vec.z = vec1.z * t;
	return (vec);
}

float	vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}
