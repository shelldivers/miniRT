/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:49:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:53:52 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "image_bonus.h"

void	ray_tracing(t_rt *rt)
{
	t_ray	ray;
	int		h;
	int		w;
	t_color	color;

	h = 0;
	ray.origin = rt->cam.view_point;
	while (h < rt->img.height)
	{
		w = 0;
		while (w < rt->img.width)
		{
			ray.direction = get_pixel_center(\
				&(rt->cam), &(rt->vw), w, h);
			color = ray_color(rt, &ray);
			put_color(&(rt->img), w, h, color_to_int(color));
			w++;
		}
		h++;
	}
}
