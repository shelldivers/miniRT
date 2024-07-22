/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:25:57 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/22 09:00:41 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT3_H
# define POINT3_H

typedef struct s_point3
{
	float	x;
	float	y;
	float	z;
}	t_point3;

t_point3	point3(float x, float y, float z);

#endif
