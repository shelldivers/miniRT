/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:59:25 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/03 01:35:26 by jeongwpa         ###   ########.fr       */
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
