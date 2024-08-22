/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:14 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/22 17:03:13 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vec3.h"
# include "ft_bool.h"
# include "hittable.h"

typedef struct s_sphere
{
	t_hit		parent;
	t_point3	center;
	float		radius;
}	t_sphere;

t_sphere	*init_sphere(t_sphere data);
t_bool		hit_sphere(t_hit *obj, t_ray const *ray, t_coll t, t_record *rec);

#endif
