/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:18:55 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/24 01:26:58 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "ft_bool.h"
# include "vec2.h"
# include "vec3.h"
# include "ray.h"
# include "image.h"

# define CHECKER_BOARD 0b00000001
# define TEXTURE_MAP 0b00000010
# define BUMP_MAP 0b00000100

enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
};

typedef struct s_quadratic
{
	t_vec3	oc;
	t_vec3	v;
	t_vec3	w;
	t_vec3	h;
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

typedef struct s_texture
{
	int			enable;
	t_vec2		uv;
	t_color		color;
	int			width_count;
	int			height_count;
	t_img		texture_map;
	t_img		bump_map;
}	t_texture;

typedef struct s_hit
{
	void			*hit;
	void			*uv_color;
	t_color			color;
	enum e_shape	shape;
	t_texture		texture;
}	t_hit;

typedef t_bool	(*t_hit_func)(t_hit *, t_ray const *, t_coll, t_record *);
typedef t_vec2	(*t_uv_map)(t_hit *obj, t_record *rec);
typedef t_color	(*t_color_map)(t_hit *obj, t_record *rec, t_uv_map);

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
