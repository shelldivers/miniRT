/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:26:25 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/22 23:38:51 by jeongwpa         ###   ########.fr       */
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
