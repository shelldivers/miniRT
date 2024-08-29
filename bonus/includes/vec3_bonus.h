/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:27:36 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:49:57 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_BONUS_H
# define VEC3_BONUS_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef t_vec3	t_point3;
typedef t_vec3	t_color;

// vec3.c
t_vec3	vec3_unit(t_vec3 vec);
float	vec3_length(t_vec3 vec);
float	vec3_length_squared(t_vec3 vec);
float	vec3_dot(t_vec3 a, t_vec3 b);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);

// vec3_utils.c
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_mul(t_vec3 a, float t);
t_vec3	vec3_div(t_vec3 a, float t);

#endif