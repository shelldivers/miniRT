/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_texture2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:12:32 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/26 01:42:48 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include "libft.h"
#include "error.h"
#include "mlx.h"

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
	must_be_positive(data->texture.height_count);
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
	data->texture.texture_map.ptr = mlx_xpm_file_to_image(rt->mlx, filename, \
		&data->texture.texture_map.width, \
		&data->texture.texture_map.height);
	free(filename);
	if (!data->texture.texture_map.ptr)
		error_exit(ERROR_OPEN_XPM_FILE);
	data->texture.texture_map.addr = mlx_get_data_addr(\
		data->texture.texture_map.ptr, \
		&data->texture.texture_map.data.bits_per_pixel, \
		&data->texture.texture_map.data.size_line, \
		&data->texture.texture_map.data.endian);
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
	data->texture.bump_map.ptr = mlx_xpm_file_to_image(rt->mlx, filename, \
		&data->texture.bump_map.width, \
		&data->texture.bump_map.height);
	free(filename);
	if (!data->texture.bump_map.ptr)
		error_exit(ERROR_OPEN_XPM_FILE);
	data->texture.bump_map.addr = mlx_get_data_addr(\
		data->texture.bump_map.ptr, \
		&data->texture.bump_map.data.bits_per_pixel, \
		&data->texture.bump_map.data.size_line, \
		&data->texture.bump_map.data.endian);
	move_to_next_param(&line);
	*ptr = line;
}
