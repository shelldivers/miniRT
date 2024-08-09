/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_vec3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:11:34 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 23:19:42 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"

static void	must_not_null_or_empty(char const *line);
static void	must_not_empty(char const *line);
static void	must_be_three_numbers(char const *line);

/**
 * @brief parse vec3 from line with format "1.0,2.0,3.0"
 * @param line	"1.0,2.0,3.0"
 * @return t_vec3
*/
t_vec3	parse_vec3(char const *line)
{
	t_vec3	vec;

	must_not_null_or_empty(line);
	must_numuric_and_comma(line);
	vec.x = ft_strtof(line, (char **)&line);
	must_not_empty(line++);
	vec.y = ft_strtof(line, (char **)&line);
	must_not_empty(line++);
	vec.z = ft_strtof(line, (char **)&line);
	must_be_three_numbers(line);
	return (vec);
}

static void	must_not_null_or_empty(char const *line)
{
	if (!line || !*line)
		error_exit(ERROR_INVALID_VEC3);
}

static void	must_not_empty(char const *line)
{
	if (*line != ',' || *(line + 1) == ',')
		error_exit(ERROR_INVALID_VEC3);
}

static void	must_be_three_numbers(char const *line)
{
	if (*line && !ft_isspace(*line))
		error_exit(ERROR_INVALID_VEC3);
}
