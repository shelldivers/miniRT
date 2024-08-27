/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:56:21 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:53:18 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_bonus.h"
#include <math.h>

/**
 * @brief 정규 벡터를 반환
 * @param vec
 * @return t_vec3
 */
t_vec3	vec3_unit(t_vec3 vec)
{
	float	length_squared;

	length_squared = vec3_length_squared(vec);
	if (length_squared == 0.0f)
		return (vec);
	return (vec3_div(vec, sqrtf(length_squared)));
}

/**
 * @brief 벡터의 길이를 반환
 * @param vec
 * @return float
 */
float	vec3_length(t_vec3 vec)
{
	float	length_squared;

	length_squared = vec3_length_squared(vec);
	return (sqrtf(length_squared));
}

/**
 * @brief 벡터의 길이의 제곱을 반환
 * @param vec
 * @return float
 */
float	vec3_length_squared(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

/**
 * @brief 두 벡터의 내적을 반환
 * @param a
 * @param b
 * @return float
 */
float	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/**
 * @brief 두 벡터의 외적을 반환
 * @param a
 * @param b
 * @return t_vec3
 */
t_vec3	vec3_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		.x = a.y * b.z - a.z * b.y,
		.y = a.z * b.x - a.x * b.z,
		.z = a.x * b.y - a.y * b.x
	});
}
