/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:57 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/23 19:26:24 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"
# include "point3.h"
# include "color.h"
# include "camera.h"
# include <stdbool.h>

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}	t_ray;

t_color		ray_color(t_ray const *ray);
t_point3	point_at(t_ray *ray, float t);
bool		hit_sphere(t_point3 center, float radius, t_ray const *ray);
t_vec3		get_direction(t_camera *camera, t_viewport *viewport, int i, int j);

#endif
