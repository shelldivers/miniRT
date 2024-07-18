/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:49:07 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 17:41:27 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# ifdef __cplusplus
extern "C" {
# endif

#include "point3.h"
#include "vec3.h"

typedef struct  s_cylinder
{
    t_point3    origin;
    t_vec3      normal;
    double      radius;
    double      height;
}	t_cylinder;

# ifdef __cplusplus
}
# endif

#endif
