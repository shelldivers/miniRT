/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:01:12 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 19:22:49 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include "shape/hittable_bonus.h"

// texture.c
t_color		uv_pattern_map(t_hit *obj, t_record *rec, t_uv_map uv_map);
t_color		uv_texture_map(t_hit *obj, t_record *rec, t_uv_map uv_map);
t_color_map	uv_color_map_adapter(t_texture texture);
t_bool		is_texture_map_enabled(t_texture texture);

// bump.c
void		normal_mapping(t_hit *obj, t_record *rec, t_uv_map uv_map);

#endif
