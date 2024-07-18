/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:25:57 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 17:04:46 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT3_H
# define POINT3_H

# ifdef __cplusplus
extern "C" {
# endif

typedef struct s_point3
{
	float	x;
	float	y;
	float	z;
}	t_point3;

t_point3	point3(float x, float y, float z);

# ifdef __cplusplus
}
# endif

#endif
