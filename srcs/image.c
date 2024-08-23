/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:32:32 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/24 01:38:28 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	put_color(t_img *img, int x, int y, unsigned int color)
{
	const int	bytes_per_pixel = img->data.bits_per_pixel / 8;
	int			pos;

	pos = y * (img->data.size_line) + x * bytes_per_pixel;
	*(unsigned int *)(img->addr + pos) = color;
}

unsigned int	get_color(t_img *img, int x, int y)
{
	const int	bytes_per_pixel = img->data.bits_per_pixel / 8;
	int			pos;

	pos = y * img->data.size_line + x * bytes_per_pixel;
	return (*(unsigned int *)(img->addr + pos));
}
