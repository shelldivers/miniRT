/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:30:48 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 00:46:03 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "ray.h"
# include "ft_bool.h"

enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_hit_record
{
	t_point3		p;
	t_vec3			normal;
	float			t;
	t_bool			front_face;
}	t_hit_record;

typedef struct s_hittable
{
	enum e_shape	shape;
	t_bool			(*hit)(struct s_hittable *obj, t_ray const *ray, \
		float ray_tmin, float ray_tmax, t_hit_record *hit_record);
}	t_hittable;

void    set_face_normal(t_hit_record *rec, t_ray const *r, t_vec3 outward_normal);


#endif