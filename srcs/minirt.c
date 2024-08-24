/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:49:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/25 02:47:11 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "image.h"
#include "key_hook.h"
#include "mlx.h"
#include "reflection.h"
#include <stdlib.h>

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
			color = get_anti_aliased_color(rt, ray, wid, hei);
			put_color(&(rt->img), wid, hei, color_to_int(color));
			wid++;
		}
		hei++;
	}
}

