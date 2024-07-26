/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:26:25 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 18:15:35 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	get_color(float r, float g, float b)
{
	t_color	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}
