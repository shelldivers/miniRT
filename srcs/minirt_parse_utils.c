/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:11:34 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/06 20:11:34 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	parse_vec3(char *line)
{
	t_vec3	vec;

	vec.x = ft_atof(line);
	while (*line && !ft_isspace(*line))
		++line;
	vec.y = ft_atof(line);
	while (*line && !ft_isspace(*line))
		++line;
	vec.z = ft_atof(line);
	return (vec);
}
