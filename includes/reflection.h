/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:29:31 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/08 17:42:54 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTION_H
# define REFLECTION_H

# include "vec3.h"

// for ambient_lightning
typedef struct s_ambient
{
	float	ratio;
	t_color	rgb;
}	t_ambient;

// for diffuse_reflection
typedef struct s_diffuse
{
	float	ratio;
	t_color	rgb;
}	t_diffuse;

// for specular_reflection
typedef struct s_specular
{
	int		power;
	float	ratio;
	t_color	rgb;
}	t_specular;

typedef struct s_phong
{
	t_ambient	ambient;
	t_diffuse	diffuse;
	t_specular	specular;
}	t_phong;

// ambient.c
t_color	get_ambient_light(t_ambient ambient);

// diffuse.c
t_vec3	random_on_hemisphere(t_vec3 normal);

// specular.c


#endif