/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:46:46 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 16:49:55 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# ifdef __cplusplus
extern "C" {
# endif

#include "point3.h"
#include "vec3.h"

typedef struct  s_plane
{
    t_point3    origin;
    t_vec3      normal;
}	t_plane;

# ifdef __cplusplus
}
# endif

#endif
