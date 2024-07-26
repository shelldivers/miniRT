/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:16:09 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/27 00:11:03 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"

typedef struct s_cam
{
	t_vec3	view_point;
	t_vec3	normal;
	int		fov;
}	t_cam;

typedef struct s_vw
{
	t_vec3		origin;
	t_vec3		horizontal;
	t_vec3		vertical;
	float		focal_length;
	t_vec3		upper_left_corner;
	t_point3	pixel00_loc;
	t_vec3		pixel_delta_u;
	t_vec3		pixel_delta_v;
}	t_vw;

t_vw	*get_viewport_malloc(t_cam *camera, int height, int width);

#endif
