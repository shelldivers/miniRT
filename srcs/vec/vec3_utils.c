/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:57:08 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/25 22:13:51 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "error.h"

/**
 * @brief 두 벡터의 합을 반환
 * @param a
 * @param b
 * @return t_vec3
 */
t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x + b.x, a.y + b.y, a.z + b.z});
}

/**
 * @brief 두 벡터의 차를 반환
 * @param a
 * @param b
 * @return t_vec3
 */
t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x - b.x, a.y - b.y, a.z - b.z});
}

/**
 * @brief 벡터와 스칼라의 곱을 반환
 * @param a
 * @param t
 * @return t_vec3
 */
t_vec3	vec3_mul(t_vec3 a, float t)
{
	return ((t_vec3){a.x * t, a.y * t, a.z * t});
}

/**
 * @brief 벡터와 스칼라의 나눗셈을 반환
 * @param a
 * @param t
 * @return t_vec3
 */
t_vec3	vec3_div(t_vec3 a, float t)
{
	float	inv_t;

	if (t == 0.0f)
		error_exit(ERROR_DIV_BY_ZERO);
	inv_t = 1.0f / t;
	return ((t_vec3){a.x * inv_t, a.y * inv_t, a.z * inv_t});
}
