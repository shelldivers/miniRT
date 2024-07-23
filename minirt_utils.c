/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:51:40 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/23 18:51:49 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_color(t_img img, int x, int y, unsigned int color)
{
	const int	bytes_per_pixel = img.data.bits_per_pixel / 8;
	int			pos;

	pos = y * img.data.size_line + x * bytes_per_pixel;
	*(unsigned int *)(img.addr + pos) = color;
}
