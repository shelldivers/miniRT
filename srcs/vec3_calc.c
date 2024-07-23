/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:30:25 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/21 00:24:04 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	vec.z = a.z + b.z;
	return (vec);
}

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return (vec);
}

t_vec3	vec3_mul(t_vec3 a, float t)
{
	t_vec3	vec;

	vec.x = a.x * t;
	vec.y = a.y * t;
	vec.z = a.z * t;
	return (vec);
}

t_vec3	vec3_div(t_vec3 a, float t)
{
	t_vec3	vec;

	vec.x = a.x / t;
	vec.y = a.y / t;
	vec.z = a.z / t;
	return (vec);
}

float	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
