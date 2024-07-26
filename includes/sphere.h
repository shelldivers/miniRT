/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:48:15 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/27 00:08:23 by jeongwpa         ###   ########.fr       */
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
	t_hit		parent;
	t_point3	center;
	float		radius;
	t_color		color;
}	t_sphere;

t_sphere	*init_sphere(t_point3 center, float radius, t_color color);
t_bool		hit_sphere(t_hit *obj, t_ray const *ray, t_coll t, t_rec *rec);
t_bool		is_collided(t_sphere *s, t_ray const *ray, float *root, t_coll t);

#endif
