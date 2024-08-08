/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_vec3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:11:34 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 22:44:42 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"

static void	move_to_next_number(char const **ptr);
static void	must_be_three_numbers(char const *line);

/**
 * @brief parse vec3 from line with format "1.0,2.0,3.0"
 * @param line	"1.0,2.0,3.0"
 * @return t_vec3
*/
t_vec3	parse_vec3(char const *line)
{
	t_vec3	vec;

	vec.x = ft_atof(line);
	move_to_next_number(&line);
	vec.y = ft_atof(line);
	move_to_next_number(&line);
	vec.z = ft_atof(line);
	must_be_three_numbers(line);
	return (vec);
}

static void	move_to_next_number(char const **ptr)
{
	char const	*line;

	line = *ptr;
	while (*line != ',')
	{
		if (!*line || ft_isspace(*line))
			error_exit(ERROR_INVALID_VEC3);
		line++;
	}
	*ptr = ++line;
}

static void	must_be_three_numbers(char const *line)
{
	while (*line && !ft_isspace(*line))
	{
		if (*line == ',')
			error_exit(ERROR_INVALID_VEC3);
		line++;
	}
}
