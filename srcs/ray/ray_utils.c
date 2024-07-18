/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:13:09 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 17:13:58 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"

t_vec3		point3_to_vec3(t_point3 p) {
    t_vec3 vec;

    vec.x = p.x;
    vec.y = p.y;
    vec.z = p.z;
    return (vec);
}

t_point3	vec3_to_point3(t_vec3 v) {
    t_point3 point;

    point.x = v.x;
    point.y = v.y;
    point.z = v.z;
    return (point);
}