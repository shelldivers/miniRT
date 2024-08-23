/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:01:12 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/23 18:35:25 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "shape/hittable.h"

// texture.c
t_color		uv_pattern_map(t_hit *obj, t_record *rec, t_uv_map uv_map);
t_color		uv_texture_map(t_hit *obj, t_record *rec, t_uv_map uv_map);
t_color_map	uv_color_map_adapter(t_texture texture);
t_bool		is_texture_map_enabled(t_texture texture);

#endif
