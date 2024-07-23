/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:16:09 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/23 17:13:47 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"

typedef struct s_camera
{
	t_vec3	view_point;
	t_vec3	normal;
	int		fov;
}	t_camera;

typedef struct s_viewport
{
	t_vec3	origin;
	int		horizontal;
	int		vertical;
	float	focal_length;
	t_vec3	lower_left_corner;
}	t_viewport;

t_viewport	*get_viewport_malloc(t_camera *camera, int height, int width);

#endif
