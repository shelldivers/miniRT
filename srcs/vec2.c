/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:46:57 by jiwojung          #+#    #+#             */
/*   Updated: 2024/07/29 15:09:55 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"
#include <math.h>

t_vec2	vec2(float x, float y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec2	vec2_zero(void)
{
	return (vec2(0.0f, 0.0f));
}

t_vec2	vec2_one(t_vec2 v1, t_vec2 v2)
{
	return (vec2(v1.x + v2.x, v1.y + v2.y));
}

t_vec2	vec2_unit(t_vec2 vec)
{
	return (vec2_div(vec, vec2_length(vec)));
}

float	vec2_length(t_vec2 v)
{
	return ((float)sqrt(v.x * v.x + v.y * v.y));
}

float	vec2_dot(t_vec2 v1, t_vec2 v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

float	vec2_slope(t_vec2 v1, t_vec2 v2)
{
	return ((v2.y - v1.y) / (v2.x - v1.x));
}
