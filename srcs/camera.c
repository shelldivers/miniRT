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
	t_vec3		tmp;

	viewport = (t_viewport *)malloc(sizeof(t_viewport));
	if (!viewport)
		return (NULL);
	viewport->origin = camera->view_point;
	viewport->horizontal = width;
	viewport->vertical = height;
	viewport->focal_length = 1;
	tmp = vec3(viewport->horizontal / 2, viewport->vertical / 2, \
		viewport->focal_length);
	viewport->lower_left_corner = vec3_sub(viewport->origin, tmp);
	return (viewport);
}
