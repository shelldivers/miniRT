/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:29:10 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/07 19:06:59 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phong_reflection.h"
#include <stdio.h>

void	tracing_ambient_light(t_hit_lst *world)
{
	t_ambient	ambient;
	t_color		ambient_light;

	ambient.ratio = 0.2;
	ambient.rgb = (t_color){255, 255, 255};
	ambient_light = get_ambient_light(ambient);
	printf ("ambient_light: %f %f %f\n", ambient_light.x, ambient_light.y, ambient_light.z);
}

t_color	get_ambient_light(t_ambient ambient)
{
	t_color	ambient_light;
	ambient.ratio = 0.2;
	ambient.rgb = (t_color){255, 255, 255};

	ambient_light = (t_color)vec3_mul(ambient.rgb, ambient.ratio);
	printf ("ambient_light: %f %f %f\n", ambient_light.x, ambient_light.y, ambient_light.z);
	return (ambient_light);
}
