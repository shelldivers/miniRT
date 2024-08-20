/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:59:25 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/20 16:41:51 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

/**
 * @brief 0~1 사이의 값을 받아서 0~255 사이의 값으로 정규화
 * @remarks 255.999를 곱해주는 이유는 형변환시 부동 소수점 연산의 반올림 오류를 방지하기 위함
 * @param color
 * @return unsigned int
 */
unsigned int	color_to_int(t_color color)
{
	return ((unsigned int)(color.x * 255.999) << 16 \
		| (unsigned int)(color.y * 255.999) << 8 \
		| (unsigned int)(color.z * 255.999));
}

/**
 * @brief u_int color를 받아서 t_color로 변환
 * @param u_int color
 * @return t_color
 */
t_color	int_to_color(unsigned int color)
{
	t_color	ret;

	ret.x = (float)((color & 0x00FF0000) >> 16) / 255.0;
	ret.y = (float)((color & 0x0000FF00) >> 8) / 255.0;
	ret.z = (float)(color & 0x000000FF) / 255.0;
	return (ret);
}

/**
 * @brief 0~255 사이의 값을 받아서 0~1 사이의 값으로 정규화
 * @param r
 * @param g
 * @param b
 * @return t_color
 */
t_color	rgb_to_color(unsigned int r, unsigned int g, unsigned int b)
{
	t_color	ret;

	ret.x = (float)r / 255.0;
	ret.y = (float)g / 255.0;
	ret.z = (float)b / 255.0;
	return (ret);
}

/**
 * @brief color a와 b를 섞어서 밝기를 중간값으로 만듬
 * @param a
 * @param b
 * @return t_color
 */
t_color	color_mix(t_color a, t_color b)
{
	return ((t_color){a.x * b.x, a.y * b.y, a.z * b.z});
}

t_color	color_add(t_color a, t_color b)
{
	float	x;
	float	y;
	float	z;

	x = a.x + b.x;
	if (x > 1.0)
		x = 1.0;
	y = a.y + b.y;
	if (y > 1.0)
		y = 1.0;
	z = a.z + b.z;
	if (z > 1.0)
		z = 1.0;
	return ((t_color){x, y, z});
}
