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
#include "libft.h"

/**
 * @brief parse vec3 from line with format "1.0,2.0,3.0"
 * @remark it is assumed that the line is in the correct format
 * @param line	"1.0,2.0,3.0"
 * @return t_vec3
*/
t_vec3	parse_vec3(char const *line)
{
	t_vec3	vec;

	vec.x = ft_atof(line);
	while (*line && *line != ',')
		line++;
	if (*line && *line == ',')
		line++;
	vec.y = ft_atof(line);
	while (*line && *line != ',')
		line++;
	if (*line && *line == ',')
		line++;
	vec.z = ft_atof(line);
	return (vec);
}
