/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:04 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/14 17:09:24 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "vec3.h"
# include "ft_bool.h"
# include "hittable.h"

typedef struct s_cone
{
	t_hit		parent;
	t_point3	center;
	t_vec3		normal;
	float		diameter;
	float		height;
	float		theta;
	t_color		color;
}	t_cone;

t_cone	*init_cone(t_cone data);
t_bool	hit_cone(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec);

#endif
