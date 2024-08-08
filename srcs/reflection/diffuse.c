/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:29:07 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/08 17:51:36 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bool.h"
#include "reflection.h"
#include "vec3.h"
#include <math.h>

static t_vec3	random_unit_vector(void);
static t_vec3	random_in_unit_sphere(void);

t_vec3	random_on_hemisphere(t_vec3 normal)
{
	t_vec3	on_unit_sphere;

	on_unit_sphere = random_unit_vector();
	if (vec3_dot(on_unit_sphere, normal) > 0)
		return (on_unit_sphere);
	else
		return (vec3_mul(on_unit_sphere, -1));
}

static t_vec3	random_unit_vector(void)
{
	return (vec3_unit(random_in_unit_sphere()));
}

static t_vec3	random_in_unit_sphere(void)
{
	t_vec3	random;

	while (TRUE)
	{
		random = vec3_random_range(-1, 1);
		if (vec3_length_squared(random) < 1)
			break ;
	}
	return (random);
}
