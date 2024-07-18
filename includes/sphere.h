/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:48:15 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 16:54:42 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# ifdef __cplusplus
extern "C" {
# endif

#include "point3.h"
#include "vec3.h"

typedef struct  s_sphere
{
    t_point3    center;
    float      radius;
}	t_sphere;


# ifdef __cplusplus
}
# endif

#endif
