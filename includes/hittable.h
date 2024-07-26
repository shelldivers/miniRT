/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:30:48 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 02:16:36 by jeongwpa         ###   ########.fr       */
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

void			set_face_normal(t_hit_record *rec, t_ray const *r, \
	t_vec3 outward_normal);

typedef struct s_hittable
{
	void			*hit;
	enum e_shape	shape;
}	t_hittable;

typedef t_bool	(*t_hit_func)(t_hittable *, t_ray const *, \
	float, float, t_hit_record *);

typedef struct s_hittable_list
{
	t_hittable	**objects;
	int			size;
	int			capacity;
}	t_hittable_list;

t_hittable_list	*init_hittable_list(int capacity);
void			add_hittable_list(t_hittable_list *list, t_hittable *object);
void			clear_hittable_list(t_hittable_list *list);
t_bool			hit_shapes(t_hittable_list *list, t_ray const *ray, \
	float t_min, float t_max, t_hit_record *rec);


#endif
