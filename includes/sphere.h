/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:48:15 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 23:59:43 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vec3.h"
# include "color.h"
# include "ft_bool.h"
# include "hittable.h"

typedef struct s_sphere
{
	t_hittable		parent;
	t_point3		center;
	float			radius;
	t_color			color;
}	t_sphere;

t_sphere	*init_sphere(t_point3 center, float radius, t_color color);
t_bool		hit_sphere(t_hittable *obj, t_ray const *ray, \
	t_collision t, t_hit_record *rec);
t_bool		is_collided(t_sphere *sphere, t_ray const *ray, \
	float *root, t_collision t);

#endif
