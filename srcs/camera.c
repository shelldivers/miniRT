/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:59:03 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/27 00:10:45 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "error.h"
#include <stdlib.h>

t_vw	*get_viewport_malloc(t_cam *camera, int height, int width)
{
	t_vw	*viewport;

	viewport = (t_vw *)malloc(sizeof(t_vw));
	if (!viewport)
		error_exit("Memory allocation failed");
	viewport->origin = camera->view_point;
	viewport->horizontal = (t_vec3){width, 0, 0};
	viewport->vertical = (t_vec3){0, -height, 0};
	viewport->focal_length = 1;
	viewport->upper_left_corner = vec3_sub(camera->view_point, \
		(t_vec3){0, 0, viewport->focal_length});
	viewport->upper_left_corner = vec3_sub(viewport->upper_left_corner, \
		vec3_div(viewport->horizontal, 2));
	viewport->upper_left_corner = vec3_sub(viewport->upper_left_corner, \
		vec3_div(viewport->vertical, 2));
	return (viewport);
}
