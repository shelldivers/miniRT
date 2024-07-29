/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:53:41 by jiwojung          #+#    #+#             */
/*   Updated: 2024/07/29 15:13:14 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

t_vec2	vec2_add(t_vec2 v1, t_vec2 v2)
{
	return (vec2(v1.x + v2.x, v1.y + v2.y));
}

t_vec2	vec2_add_scalar(t_vec2 v, float scalar)
{
	return (vec2(v.x + scalar, v.y + scalar));
}

t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2)
{
	return (vec2(v1.x - v2.x, v1.y - v2.y));
}

t_vec2	vec2_sub_scalar(t_vec2 v, float scalar)
{
	return (vec2(v.x - scalar, v.y - scalar));
}

t_vec2	vec2_mul(t_vec2 v, float scalar)
{
	return (vec2(v.x * scalar, v.y * scalar));
}

t_vec2	vec2_div(t_vec2 v, float scalar)
{
	if (scalar == 0)
		return (vec2_zero());
	return (vec2(v.x / scalar, v.y / scalar));
}
