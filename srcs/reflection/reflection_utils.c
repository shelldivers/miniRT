/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:35:44 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/20 19:38:31 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec3.h"
#include "reflection.h"

t_bool	near_zero(const t_vec3 v)
{
	const double	s = 1e-8;

	return (fabs(v.x) < s && fabs(v.y) < s && fabs(v.z) < s);
}
