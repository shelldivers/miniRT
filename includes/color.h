/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:15:18 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/08 14:17:19 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "minirt.h"
# include "vec3.h"

unsigned int	color_to_int_ratio(t_color color);
unsigned int	color_to_int_rgb(t_color color);
t_color			rgb_to_color(unsigned int r, unsigned int g, unsigned int b);

void			put_color(t_img *img, int x, int y, unsigned int color);
t_color			ray_color(t_ray const *ray, t_hit_lst *world);

#endif