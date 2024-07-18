/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:46:46 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 17:48:43 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# ifdef __cplusplus
extern "C" {
# endif

#include "vec3.h"
#include "point3.h"
#include "color.h"

typedef struct  s_plane
{
    t_point3    origin;
    t_vec3      normal;
    t_color     color;
}	t_plane;

# ifdef __cplusplus
}
# endif

#endif
