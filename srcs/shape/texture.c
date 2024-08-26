/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:57:47 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/26 16:02:46 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/hittable.h"
#include "shape/texture.h"
#include "error.h"
#include "image.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

t_color	uv_pattern_map(t_hit *obj, t_record *rec, t_uv_map uv_map)
{
	t_vec2		uv;
	int			u2;
	int			v2;

	uv = uv_map(obj, rec);
	u2 = floor(uv.u * obj->texture.width_count);
	v2 = floor(uv.v * obj->texture.height_count);
	if ((u2 + v2) % 2 == 0)
		return (obj->color);
	return (obj->texture.color);
}

t_color	uv_texture_map(t_hit *obj, t_record *rec, t_uv_map uv_map)
{
	t_vec2		uv;
	int			u2;
	int			v2;
	int			pixel_color;
	t_img		*texture_map;

	uv = uv_map(obj, rec);
	texture_map = &obj->texture.texture_map;
	u2 = floor(uv.u * obj->texture.width_count);
	v2 = floor(uv.v * obj->texture.height_count);
	pixel_color = texture_map->addr[u2 * v2];
	return (int_to_color(pixel_color));
}

t_color_map	uv_color_map_adapter(t_texture texture)
{
	if ((texture.enable & 0b00000011) == (CHECKER_BOARD | TEXTURE_MAP))
		error_exit(ERROR_TEXTURE_DUPLICATE);
	if (texture.enable & CHECKER_BOARD)
		return (uv_pattern_map);
	if (texture.enable & TEXTURE_MAP)
		return (uv_texture_map);
	error_exit(ERROR_TEXTURE_NOT_FOUND);
	return (NULL);
}

t_bool	is_texture_map_enabled(t_texture texture)
{
	if (texture.enable & (CHECKER_BOARD | TEXTURE_MAP))
		return (TRUE);
	return (FALSE);
}
