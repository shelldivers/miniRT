/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:48:15 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 17:49:20 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# ifdef __cplusplus
extern "C" {
# endif

#include "vec3.h"
#include "point3.h"
#include "color.h"

typedef struct  s_sphere
{
    t_point3    center;
    float       radius;
    t_color     color
}	t_sphere;


# ifdef __cplusplus
}
# endif

#endif
