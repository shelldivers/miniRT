/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:48:19 by jiwojung          #+#    #+#             */
/*   Updated: 2024/07/29 15:09:58 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

// vec2
t_vec2	vec2(float x, float y);
t_vec2	vec2_zero(void);
t_vec2	vec2_one(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_unit(t_vec2 vec);
float	vec2_length(t_vec2 v);
float	vec2_dot(t_vec2 v1, t_vec2 v2);
float	vec2_slope(t_vec2 v1, t_vec2 v2);


// vec2_utils
t_vec2	vec2_add(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_add_scalar(t_vec2 v, float scalar);
t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_sub_scalar(t_vec2 v, float scalar);
t_vec2	vec2_mul(t_vec2 v, float scalar);
t_vec2	vec2_div(t_vec2 v, float scalar);

#endif