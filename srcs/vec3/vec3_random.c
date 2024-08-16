/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:48:01 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/16 13:31:36 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <stdlib.h>
#include <sys/time.h>

static float	random_float(void);

/**
 * @brief return random vec3 number from 0 to 1
 * @return t_vec3
 */
t_vec3	vec3_random(void)
{
	return ((t_vec3){random_float(), \
					random_float(), \
					random_float()});
}

/*
* @brief return random vec3 number from min to max
* @param min
* @param max
* @return t_vec3
*/
t_vec3	vec3_random_range(float min, float max)
{
	return ((t_vec3){random_float() * (max - min) + min, \
					random_float() * (max - min) + min, \
					random_float() * (max - min) + min});
}

/*
* @brief return random float number from 0 to 1
* @return float
*/
static float	random_float(void)
{
	return ((float)rand() / RAND_MAX);
}
