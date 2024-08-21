/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:36:09 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:57 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"
# include "camera.h"

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}	t_ray;

// ray.c
t_point3		point_at(t_ray const *ray, float t);
t_vec3			get_direction(t_camera *cam, t_viewport *vw, int i, int j);

// color.ct_viewport
unsigned int	color_to_int(t_color color);
t_color			int_to_color(unsigned int color);

#endif
