/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:19:51 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/22 09:00:37 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

// vec3.c
t_vec3	vec3(float x, float y, float z);
t_vec3	vec3_unit(t_vec3 vec);
float	vec3_length(t_vec3 vec);

// vec3_calc.c
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_mul(t_vec3 a, float t);
t_vec3	vec3_div(t_vec3 a, float t);
float	vec3_dot(t_vec3 a, t_vec3 b);

#endif
