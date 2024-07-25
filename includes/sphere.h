/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:48:15 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 00:19:06 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vec3.h"
# include "point3.h"
# include "color.h"
# include "ft_bool.h"
# include "hittable.h"

typedef struct s_sphere
{
	t_hittable		parent;
	t_point3		center;
	float			radius;
	t_color			color;
}	t_sphere;

t_sphere	*init_sphere(t_point3 center, float radius, t_color color);
t_bool		hit_sphere(t_hittable *obj, t_ray const *ray, float ray_tmin, float ray_tmax, t_hit_record *rec);

#endif
