/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:26:25 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/23 18:46:38 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color(float r, float g, float b)
{
	t_color	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

unsigned int	color_to_int(t_color color)
{
	return ((unsigned int)(color.x * 255.999) << 16 \
		| (unsigned int)(color.y * 255.999) << 8 \
		| (unsigned int)(color.z * 255.999));
}
