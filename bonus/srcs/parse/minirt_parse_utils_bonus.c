/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:11:34 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:51:13 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "error_bonus.h"
#include "libft.h"

void	skip_spaces(char const **ptr)
{
	char const	*line;

	line = *ptr;
	while (*line && ft_isspace(*line))
		line++;
	*ptr = line;
}

void	move_to_next_param(char const **ptr)
{
	char const	*line;

	line = *ptr;
	while (*line && !ft_isspace(*line))
		line++;
	skip_spaces(&line);
	*ptr = line;
}

void	must_numuric_and_comma(char const *line)
{
	const char	*list = "0123456789,.+-";

	while (*line)
	{
		if (ft_isspace(*line))
			break ;
		if (!ft_strchr(list, *line) && !ft_isspace(*line))
			error_exit(ERROR_INVALID_PARAM);
		line++;
	}
}

void	must_be_last_vec3(char const *line)
{
	move_to_next_param(&line);
	if (*line)
		error_exit(ERROR_INVALID_PARAM);
}

void	must_be_last_number(char const *line)
{
	skip_spaces(&line);
	if (*line)
		error_exit(ERROR_INVALID_PARAM);
}
