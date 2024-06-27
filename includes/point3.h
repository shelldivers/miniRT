/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:25:57 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/06/26 19:09:38 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT3_H
# define POINT3_H

# ifdef __cplusplus
extern "C" {
# endif

# include "vec3.h"

typedef struct s_point3
{
	t_vec3	pos;
}	t_point3;

t_point3	point3(double x, double y, double z);

# ifdef __cplusplus
}
# endif

#endif
