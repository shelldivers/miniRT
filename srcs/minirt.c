/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:49:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/25 11:14:28 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "image.h"

void	ray_tracing(t_rt *rt)
{
	t_ray	ray;
	int		hei;
	int		wid;
	t_color	color;

	hei = 0;
	ray.origin = rt->cam.view_point;
	while (hei < rt->img.height)
	{
		wid = 0;
		while (wid < rt->img.width)
		{
			ray.direction = get_pixel_center(&(rt->cam), &(rt->vw), wid, hei);
			color = ray_color(rt, &ray);
			put_color(&(rt->img), wid, hei, color_to_int(color));
			wid++;
		}
		hei++;
	}
}
