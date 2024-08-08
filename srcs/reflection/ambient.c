/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:29:10 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/08 17:34:46 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "shape/hittable.h"
#include "reflection.h"

t_color	get_ambient_light(t_ambient ambient)
{
	t_color	ambient_light;

	ambient.ratio = 0.2;
	ambient.rgb = (t_color){255, 255, 255};
	ambient_light = (t_color)vec3_mul(ambient.rgb, ambient.ratio);
	return (ambient_light);
}
