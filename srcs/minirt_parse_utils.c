/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:11:34 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 22:44:13 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"

void	skip_spaces(char const **ptr)
{
	char const	*line;

	line = *ptr;
	while (*line && ft_isspace(*line))
		++line;
	*ptr = line;
}

void	move_to_next_param(char const **ptr)
{
	char const	*line;

	line = *ptr;
	while (*line && !ft_isspace(*line))
		++line;
	*ptr = line;
}

void	must_be_last_param(char const *line)
{
	move_to_next_param(&line);
	if (*line)
		error_exit(ERROR_INVALID_PARAM);
}
