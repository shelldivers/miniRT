/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:26:19 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:49:40 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_BONUS_H
# define IMAGE_BONUS_H

typedef struct s_data
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	t_data	data;
	int		width;
	int		height;
}	t_img;

unsigned int	get_color(t_img *img, int x, int y);
void			put_color(t_img *img, int x, int y, unsigned int color);

#endif