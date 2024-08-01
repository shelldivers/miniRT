/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:31:09 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/01 13:59:12 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "ray.h"

t_ray	ray(const t_vec3 orig, const t_vec3 dir)
{
	t_ray	ray;

	// ray starting point
	ray.orig = orig;
	// ray direction
	ray.dir = dir;
	return (ray);
}

// scalar multiple of ray direction
t_vec3	ray_at(const t_ray *r, float t)
{
	return (vec3_add(r->orig, vec3_mul(r->dir, t)));
}


