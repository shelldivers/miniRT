/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:19:54 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/14 00:05:35 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vec3.h"
# include "ft_bool.h"
# include "hittable.h"

typedef struct s_cylinder
{
	t_hit		parent;
	t_point3	center;
	t_point3	top;
	t_point3	bottom;
	t_vec3		normal;
	float		radius;
	float		height;
	t_color		color;
}	t_cylinder;

t_cylinder	*init_cylinder(t_cylinder data);
t_bool		hit_cylinder(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec);

#endif
