/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:18:55 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/15 01:04:48 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "ft_bool.h"
# include "vec3.h"
# include "ray.h"

enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_quadratic
{
	t_vec3	oc;
	t_vec3	u;
	t_vec3	v;
	float	a;
	float	b;
	float	c;
}	t_quadratic;

typedef struct s_record
{
	t_point3	p;
	t_vec3		normal;
	float		t;
	t_bool		front_face;
	t_color		color;
}	t_record;

typedef struct s_coll
{
	float	min;
	float	max;
}	t_coll;

typedef struct s_hit
{
	void			*hit;
	enum e_shape	shape;
}	t_hit;

typedef t_bool	(*t_hit_func)(t_hit *, t_ray const *, t_coll, t_record *);

typedef struct s_hit_lst
{
	t_hit	**objects;
	int		size;
	int		capacity;
}	t_hit_lst;


t_hit_lst	*init_hittable_list(int capacity);
void		add_hittable_list(t_hit_lst *list, t_hit *object);
void		clear_hittable_list(t_hit_lst *list);
t_bool		hit_shapes( \
	t_hit_lst *list, t_ray const *ray, t_coll t, t_record *rec);

void		set_face_normal( \
	t_record *rec, t_ray const *r, t_vec3 outward_normal);

t_bool		quadratic_equation(t_quadratic var, t_coll t, float *root);

#endif
