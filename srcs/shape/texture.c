/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:57:47 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/23 01:26:26 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/hittable.h"
#include "shape/texture.h"
#include "error.h"
#include <stdlib.h>

t_color	uv_pattern_map(t_hit *obj, t_record *rec)
{
	(void)obj;
	(void)rec;
	return (rec->color);
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
