/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:30:48 by jiwojung          #+#    #+#             */
/*   Updated: 2024/07/29 15:38:27 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct t_ray
{
	t_vec3	orig;
	t_vec3	dir;
}	t_ray;

t_ray	ray(const t_vec3 orig, const t_vec3 dir);
t_vec3	ray_at(const t_ray *r, float t);

#endif