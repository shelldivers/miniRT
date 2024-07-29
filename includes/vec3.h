/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:19:51 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/29 15:10:45 by jiwojung         ###   ########.fr       */
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
t_vec3	vec3_zero(void);

// vec3_utils.c
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_mul(t_vec3 v, float t);
t_vec3	vec3_div(t_vec3 v, float t);
float	vec3_dot(t_vec3 v1, t_vec3 v2);

#endif
