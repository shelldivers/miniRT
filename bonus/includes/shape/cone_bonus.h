/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:04 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:49:02 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_BONUS_H
# define CONE_BONUS_H

# include "vec3.h"
# include "ft_bool.h"
# include "hittable.h"

typedef struct s_cone
{
	t_hit		parent;
	t_point3	center;
	t_point3	top;
	t_point3	bottom;
	t_vec3		normal;
	float		radius;
	float		height;
}	t_cone;

t_cone	*init_cone(t_cone data);
t_bool	hit_cone(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec);
t_vec2	get_uv_map_cone(t_hit *obj, t_record *rec);

float	hit_cone_surface(t_cone *co, t_ray const *ray, t_coll t);
float	hit_cone_endcaps(t_cone *co, t_ray const *ray, t_coll t);

#endif
