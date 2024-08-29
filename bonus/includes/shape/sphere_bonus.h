/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:14 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 19:22:13 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_BONUS_H
# define SPHERE_BONUS_H

# include "vec3_bonus.h"
# include "ft_bool.h"
# include "hittable_bonus.h"

typedef struct s_sphere
{
	t_hit		parent;
	t_point3	center;
	float		radius;
}	t_sphere;

t_sphere	*init_sphere(t_sphere data);
t_bool		hit_sphere(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec);
t_vec2		get_uv_map_sphere(t_hit *obj, t_record *rec);

#endif