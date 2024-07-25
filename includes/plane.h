/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:46:46 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/25 19:49:57 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "vec3.h"
# include "point3.h"
# include "color.h"

typedef struct s_plane
{
	t_point3	origin;
	t_vec3		normal;
	t_color		color;
}	t_plane;

typedef struct s_plane_hit
{
	t_point3	point;
	t_vec3		normal;
	t_color		color;
}	t_plane_hit;

#endif
