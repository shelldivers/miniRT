/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:41:02 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:49:36 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_BONUS_H
# define CAMERA_BONUS_H

# include "vec3.h"

typedef struct s_camera
{
	t_vec3	view_point;
	t_vec3	normal;
	float	fov;
}	t_camera;

typedef struct s_vw_var
{
	t_vec3		look_from;
	t_vec3		look_at;
	t_vec3		view_up;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;
	float		viewport_height;
	float		viewport_width;
	t_vec3		viewport_u;
	t_vec3		viewport_v;
}	t_vw_var;

typedef struct s_viewport
{
	t_vec3		origin;
	t_vec3		horizontal;
	t_vec3		vertical;
	float		focal_length;
	t_vec3		upper_left_corner;
	t_point3	pixel00_loc;
	t_vec3		pixel_delta_u;
	t_vec3		pixel_delta_v;
}	t_viewport;

#endif
