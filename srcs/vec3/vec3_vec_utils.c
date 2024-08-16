/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_vec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:28:58 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/16 13:35:37 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

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
	return ((t_vec3){a.x / t, a.y / t, a.z / t});
}

/**
 * @brief calculate the multiple of two vectors
 * @param t_vec3 v1
 * @param t_vec3 v2
 * @return t_vec3
 */
t_vec3	vec3_mul_vec(t_vec3 v1, t_vec3 v2)
{
	return ((t_vec3){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

/**
 * @brief calculate the divide of two vectors
 * @param t_vec3 v1
 * @param t_vec3 v2
 * @return t_vec3
 */
t_vec3	vec3_div_vec(t_vec3 v1, t_vec3 v2)
{
	return ((t_vec3){v1.x / v2.x, v1.y / v2.y, v1.z * v2.z});
}
