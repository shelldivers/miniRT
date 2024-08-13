/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:11:34 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/11 02:06:00 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"

void	normalize_color_value(t_color *color)
{
	if (color->x < 0 || color->x > 255)
		error_exit(ERROR_INVALID_COLOR);
	if (color->y < 0 || color->y > 255)
		error_exit(ERROR_INVALID_COLOR);
	if (color->z < 0 || color->z > 255)
		error_exit(ERROR_INVALID_COLOR);
	color->x /= 255;
	color->y /= 255;
	color->z /= 255;
}

void	must_be_valid_normal(t_vec3 normal)
{
	if (normal.x < -1 || normal.x > 1)
		error_exit(ERROR_INVALID_NORMAL);
	if (normal.y < -1 || normal.y > 1)
		error_exit(ERROR_INVALID_NORMAL);
	if (normal.z < -1 || normal.z > 1)
		error_exit(ERROR_INVALID_NORMAL);
}

void	must_be_valid_ratio(float ratio)
{
	if (ratio < 0 || ratio > 1)
		error_exit(ERROR_INVALID_RATIO);
}

void	must_have_no_remain(char const *line)
{
	if (!ft_isspace(*line))
		error_exit(ERROR_INVALID_PARAM);
}
