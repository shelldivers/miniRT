/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:09:37 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/15 10:49:28 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	random_in_unit_sphere(void)
{
	t_vec3	p;

	while (1)
	{
		p = vec3_random_range(-1, 1);
		if (vec3_length_squred(p) >= 1)
			break ;
	}
	return (p);
}

t_vec3	random_unit_vector(void)
{
	return (vec3_unit(random_in_unit_sphere()));
}

t_vec3	random_on_hemisphere(t_vec3 normal)
{
	t_vec3	in_unit_sphere;

	in_unit_sphere = random_unit_vector();
	if (vec3_dot(in_unit_sphere, normal) > 0.0)
		return (in_unit_sphere);
	else
		return (vec3_mul(in_unit_sphere, -1));
}
