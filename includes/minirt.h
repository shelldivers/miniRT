/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:30 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/23 18:51:30 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define SIZE_X 1920
# define SIZE_Y 1080
# define WIDTH SIZE_X
# define HEIGHT SIZE_Y

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
}	t_img;

void	put_color(t_img img, int x, int y, unsigned int color);

#endif
