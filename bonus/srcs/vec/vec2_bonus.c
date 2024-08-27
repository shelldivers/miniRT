/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:24:12 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/27 18:53:16 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2_bonus.h"

t_vec2	vec2_add(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){a.u + b.u, a.v + b.v});
}

t_vec2	vec2_sub(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){a.u - b.u, a.v - b.v});
}
