/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:25:57 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/22 22:52:39 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT3_H
# define POINT3_H

# include "vec3.h"

typedef struct s_point3
{
	t_vec3	pos;
}	t_point3;

t_point3	point3(double x, double y, double z);

#endif
