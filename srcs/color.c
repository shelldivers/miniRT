/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:26:25 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/21 00:27:31 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color(float r, float g, float b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_vec3	color_to_vec3(t_color color)
{
	return (vec3(color.r, color.g, color.b));
}

t_color	vec3_to_color(t_vec3 vec)
{
	return (color(vec.x, vec.y, vec.z));
}
