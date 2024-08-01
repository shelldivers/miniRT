/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:36:17 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/01 17:36:18 by jeongwpa         ###   ########.fr       */
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

#endif
