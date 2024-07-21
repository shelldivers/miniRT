/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:57 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/21 16:21:38 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# ifdef __cplusplus
extern "C" {
# endif

#include "vec3.h"
#include "point3.h"
#include "color.h"
#include <stdbool.h>

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}	t_ray;

t_point3	point_at(t_ray *ray, float t);
bool		hit_sphere(t_point3 center, float radius, t_ray const *ray);
t_color		ray_color(t_ray const *ray);

t_vec3		point3_to_vec3(t_point3 p);
t_point3	vec3_to_point3(t_vec3 v);

# ifdef __cplusplus
}
# endif

#endif
