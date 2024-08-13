/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:29:10 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/13 18:58:34 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_color	embient_lighting(t_color color, t_color ambient_light)
{
	return ((t_color){color.x * ambient_light.x, \
					color.y * ambient_light.y, \
					color.z * ambient_light.z});
}
