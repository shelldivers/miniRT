/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:57:08 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/16 13:35:08 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

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
 * @brief calculate the add of vector and scalar
 * @param t_vec3 a
 * @param float val
 * @return t_vec3
 */
t_vec3	vec3_add_val(t_vec3 a, float val)
{
	return ((t_vec3){a.x + val, a.y + val, a.z + val});
}

/**
 * @brief calculate the sub of vector and scalar
 * @param t_vec a
 * @param float val
 * @return t_vec3
 */
t_vec3	vec3_sub_val(t_vec3 a, float val)
{
	return ((t_vec3){a.x - val, a.y - val, a.z - val});
}
