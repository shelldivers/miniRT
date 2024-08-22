/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_texture2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:12:32 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/22 21:13:04 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"
#include <mlx.h>

void	parse_checkerboard(t_rt *rt, t_hit *data, char const **ptr)
{
	char const	*line;

	(void)rt;
	line = *ptr;
	line += 2;
	skip_spaces(&line);
	data->texture.color = parse_vec3(line);
	normalize_color_value(&data->texture.color);
	move_to_next_param(&line);
	data->texture.width_count = ft_strtoi(line, (char **)&line);
	must_have_no_remain(line);
	must_be_positive(data->texture.width_count);
	move_to_next_param(&line);
	data->texture.height_count = ft_strtoi(line, (char **)&line);
	must_have_no_remain(line);
	must_be_positive(data->texture.width_count);
	*ptr = line;
}

void	parse_texture_map(t_rt *rt, t_hit *data, char const **ptr)
{
	char const	*line;
	char		*filename;

	line = *ptr;
	line += 2;
	skip_spaces(&line);
	filename = substr_filename(line);
	must_have_valid_extension(filename, ".xpm");
	data->texture.texture_map = mlx_xpm_file_to_image(rt->mlx, filename, \
		&data->texture.texture_width, \
		&data->texture.texture_height);
	free(filename);
	if (!data->texture.texture_map)
		error_exit(ERROR_OPEN_XPM_FILE);
	move_to_next_param(&line);
	*ptr = line;
}

void	parse_bump_map(t_rt *rt, t_hit *data, char const **ptr)
{
	char const	*line;
	char		*filename;

	line = *ptr;
	line += 2;
	skip_spaces(&line);
	filename = substr_filename(line);
	must_have_valid_extension(filename, XPM_EXTENSION);
	data->texture.bump_map = mlx_xpm_file_to_image(rt->mlx, filename, \
		&data->texture.bump_width, \
		&data->texture.bump_height);
	free(filename);
	if (!data->texture.bump_map)
		error_exit(ERROR_OPEN_XPM_FILE);
	move_to_next_param(&line);
	*ptr = line;
}
