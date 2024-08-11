/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:04 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 22:40:21 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "vec3.h"
# include "ft_bool.h"
# include "hittable.h"

typedef struct s_plane
{
	t_hit		parent;
	t_point3	center;
	t_vec3		normal;
	t_color		color;
}	t_plane;

t_plane	*init_plane(t_plane data);
t_bool	hit_plane(t_hit *obj, t_ray const *ray, t_coll t, t_rec *rec);

#endif
