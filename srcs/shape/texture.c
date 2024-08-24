/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:57:47 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/24 01:41:22 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/hittable.h"
#include "shape/texture.h"
#include "error.h"
#include "image.h"
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
	(void)obj;
	(void)rec;
	(void)uv_map;
	return (rec->color);
}

t_color_map	uv_color_map_adapter(t_texture texture)
{
	if ((texture.enable & 0b00000011) == (CHECKER_BOARD | TEXTURE_MAP))
		error_exit(ERROR_DUPLICATE_TEXTURE);
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
