/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:57:47 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/23 01:37:06 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/hittable.h"
#include "shape/texture.h"
#include "error.h"
#include <stdlib.h>

t_color	uv_pattern_map(t_hit *obj, t_record *rec)
{
	t_uv_map	uv_map;
	t_vec2		uv;
	int			u2;
	int			v2;

	uv_map = obj->uv_map;
	uv = uv_map(obj, rec);
	u2 = (int)floor(uv.u);
	v2 = (int)floor(uv.v);
	if ((u2 + v2) % 2 == 0)
		return (rec->color);
	return (obj->texture.color);
}

t_color	uv_texture_map(t_hit *obj, t_record *rec)
{
	(void)obj;
	(void)rec;
	return (rec->color);
}

t_color_map	uv_color_map_adapter(t_texture texture)
{
	if (texture.enable >= (CHECKER_BOARD | TEXTURE_MAP))
		error_exit(ERROR_DUPLICATE_TEXTURE);
	if (texture.enable == CHECKER_BOARD)
		return (uv_pattern_map);
	if (texture.enable == TEXTURE_MAP)
		return (uv_texture_map);
	error_exit(ERROR_TEXTURE_NOT_FOUND);
	return (NULL);
}
