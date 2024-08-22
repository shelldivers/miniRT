/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:40:31 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/22 15:00:46 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTION_H
# define REFLECTION_H

# include "vec3.h"
# include "shape/hittable.h"

# define REFLECTION_CONST 0.5
# define SHININESS_CONST 20

typedef struct s_light
{
	t_point3	center;
	float		ratio;
	t_color		color;
}	t_light;

typedef struct s_light_lst
{
	t_light	**objects;
	int		size;
	int		capacity;
}	t_light_lst;

typedef struct s_ambient
{
	float		ratio;
	t_color		color;
	t_color		light;
}	t_ambient;

t_light_lst	*init_light_list(int capacity);
void		add_light_list(t_light_lst *list, t_light *light);
void		clear_light_list(t_light_lst *list);

// reflection.c
t_color		get_diffused_luminance(t_record *rec, t_light *light);
t_color		get_specular_luminance(\
				t_record *rec, t_light *light, t_camera *cam);
t_bool		is_shadowed(t_light *light, t_record *rec, t_hit_lst *world);

// reflection_utils.c
t_color		set_light_color(t_color object_color, t_color light_color);
t_color		light_add(t_color l1, t_color l2);

#endif
