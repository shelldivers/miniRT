/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:49:07 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/22 09:07:45 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vec3.h"
# include "point3.h"
# include "color.h"

typedef struct s_cylinder
{
	t_point3	origin;
	t_vec3		normal;
	float		radius;
	float		height;
	t_color		color;
}	t_cylinder;

#endif
