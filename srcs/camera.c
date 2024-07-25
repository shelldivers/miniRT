/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:59:03 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/23 19:16:26 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <stdlib.h>

t_viewport	*get_viewport_malloc(t_camera *camera, int height, int width)
{
	t_viewport	*viewport;

	viewport = (t_viewport *)malloc(sizeof(t_viewport));
	if (!viewport)
		return (NULL);
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
