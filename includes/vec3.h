/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:19:51 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/06/26 18:41:30 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# ifdef __cplusplus
extern "C" {
# endif

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

// vec3.c
t_vec3	vec3(double x, double y, double z);

// vec3_utils.c
t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_sub(t_vec3 vec1, t_vec3 vec2);
double	vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_mul(t_vec3 vec1, double t);
double	vec_length(t_vec3 v);

# ifdef __cplusplus
}
# endif

#endif
