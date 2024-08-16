/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:40:31 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/16 17:22:11 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTION_H
# define REFLECTION_H

# include "vec3.h"
# include "shape/hittable.h"

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

// diffuse.c
t_color		get_diffused(t_record *rec, t_light *light);

// t_vec3		random_in_unit_sphere(void);
// t_vec3		random_unit_vector(void);
// t_vec3		random_on_hemisphere(t_vec3 normal);

#endif
