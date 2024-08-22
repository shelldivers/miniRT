/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:18:26 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/22 17:29:35 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

/**
 * @brief Check if the line contains a texture option.
 *        The texture option is "-c", "-t", or "-b".
 *        "-c" is for checkerboard
 *        "-t" is for texture image,
 *        "-b" is for bump map.
 * @param line The line to check
 * @return t_bool TRUE if the line contains a texture option, FALSE otherwise
 */
t_bool	has_texture(char const *line)
{
	const char	*options = "ctb";

	move_to_next_param(&line);
	if (*line++ != '-')
		return (FALSE);
	if (!*(line + 1) || !ft_isspace(*(line + 1)))
		return (FALSE);
	while (*options)
	{
		if (*line == *(options++))
			return (TRUE);
	}
	return (FALSE);
}

void	parse_texture(t_hit *data, char const *line)
{
}

void	parse_checkerboard(t_hit *data, char const *line)
{
}

void	parse_texture_image(t_hit *data, char const *line)
{
}
