/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:21:09 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/18 16:54:06 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# ifdef __cplusplus
extern "C" {
#endif

# include "vec3.h"

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

t_color	color(float r, float g, float b);

# ifdef __cplusplus
}
# endif

#endif
