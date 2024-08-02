/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:56:21 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/02 23:57:21 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

t_vec3	vec3_unit(t_vec3 vec)
{
	return (vec3_div(vec, vec3_length(vec)));
}

float	vec3_length(t_vec3 vec)
{
	return (sqrtf(vec3_length_squred(vec)));
}

float	vec3_length_squred(t_vec3 vec)
{
	return ((float) vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
