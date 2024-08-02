/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:36:09 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/02 23:59:58 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"
# include "camera.h"

typedef t_vec3	t_color;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}	t_ray;

// ray.c
t_point3		point_at(t_ray const *ray, float t);
t_vec3			get_direction(t_cam *camera, t_vw *viewport, int i, int j);

// color.c
unsigned int	color_to_int(t_color color);

#endif
