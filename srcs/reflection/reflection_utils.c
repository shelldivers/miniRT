/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:35:44 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/21 14:25:39 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec3.h"
#include "reflection.h"

/**
 * @brief illuminate the object with light, 
 * 			allowing it to reflect based on its own reflection ratio(RGB)
 * @return t_color ray_color
 */
t_color	illuminate_object(t_color object_color, t_color light_color)
{
	return ((t_color){\
					object_color.x * light_color.x, \
					object_color.y * light_color.y, \
					object_color.z * light_color.z});
}

/**
 * @brief combine two light brightnesses
 * @return t_color l1 + l2
 */
t_color	light_add(t_color l1, t_color l2)
{
	float	r;
	float	g;
	float	b;

	r = l1.x + l2.x;
	if (r > 1)
		r = 1;
	g = l1.y + l2.y;
	if (g > 1)
		g = 1;
	b = l1.z + l2.z;
	if (b > 1)
		b = 1;
	return ((t_color){r, g, b});
}
