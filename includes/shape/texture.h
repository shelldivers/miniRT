/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:01:12 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/23 01:23:56 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "shape/hittable.h"

// texture.c
t_color		uv_pattern_map(t_hit *obj, t_record *rec);
t_color		uv_texture_map(t_hit *obj, t_record *rec);
t_color_map	uv_color_map_adapter(t_texture texture);

#endif
