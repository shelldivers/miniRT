/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:18:26 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/26 10:00:04 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "minirt.h"
#include "libft.h"
#include "error.h"

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

void	parse_texture(t_rt *rt, t_hit *data, char const **ptr)
{
	char const			*line;
	t_texture_parser	texture_parser;

	line = *ptr;
	data->texture.enable = FALSE;
	move_to_next_param(&line);
	while (*line)
	{
		skip_spaces(&line);
		if (!*line)
			break ;
		texture_parser = parse_texture_adapter(data, line);
		texture_parser(rt, data, &line);
	}
	*ptr = line;
}

t_texture_parser	parse_texture_adapter(t_hit *data, char const *line)
{
	int						pos;
	int						option;
	const char				*options = "ctb";
	const t_texture_parser	parsers[] = {
		parse_checkerboard,
		parse_texture_map,
		parse_bump_map
	};

	line++;
	while (*options)
	{
		if (*line == *options)
		{
			pos = options - "ctb";
			option = 1 << pos;
			if (data->texture.enable & option)
				error_exit(ERROR_TEXTURE_DUPLICATE);
			data->texture.enable |= option;
			return (parsers[pos]);
		}
		options++;
	}
	error_exit(ERROR_INVALID_TEXTURE_OPTION);
	return (NULL);
}
