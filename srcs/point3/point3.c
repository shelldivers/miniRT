/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:26:35 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/06/26 19:09:35 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3.h"

t_point3	point3(double x, double y, double z)
{
	t_point3	point;

	point.pos = vec3(x, y, z);
	return (point);
}
