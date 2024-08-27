/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:03:05 by jiwojung          #+#    #+#             */
/*   Updated: 2024/08/27 18:52:16 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape/hittable_bonus.h"
#include "shape/map_bonus.h"
#include "image_bonus.h"
#include "parse_bonus.h"
#include "vec2_bonus.h"
#include <math.h>
#include <stdlib.h>

t_vec3	get_normal_map(t_vec3 color, t_record *rec);
void	set_tangents(t_vec3 *t, t_vec3 *b);
t_vec3	matrix_mul_vec3(t_vec3 t, t_vec3 b, t_vec3 n, t_vec3 normal_map);

void	normal_mapping(t_hit *obj, t_record *rec, t_uv_map uv_map)
{
	t_vec2			uv;
	int				u2;
	int				v2;
	t_vec3			color;
	t_img			*bump_map;

	uv = uv_map(obj, rec);
	bump_map = &obj->texture.bump_map;
	u2 = floor(uv.u * (bump_map->width - 1));
	if (u2 < 0)
		u2 = 0;
	else if (u2 >= bump_map->width)
		u2 = bump_map->width - 1;
	v2 = floor(uv.v * (bump_map->height - 1));
	if (v2 < 0)
		v2 = 0;
	else if (v2 >= bump_map->height)
		v2 = bump_map->height - 1;
	color = int_to_color(get_color(bump_map, u2, v2));
	rec->normal = get_normal_map(color, rec);
}

t_vec3	get_normal_map(t_vec3 color, t_record *rec)
{
	t_vec3	t;
	t_vec3	b;
	t_vec3	normal_map;

	normal_map = vec3_sub(vec3_mul(color, 2), (t_vec3){1, 1, 1});
	set_tangents(&t, &b);
	return (matrix_mul_vec3(t, b, rec->normal, normal_map));
}

void	set_tangents(t_vec3 *t, t_vec3 *b)
{
	const t_vec3	edge1 = vec3_sub((t_vec3){-1, -1, 0}, (t_vec3){-1, 0, 0});
	const t_vec3	edge2 = vec3_sub((t_vec3){0, -1, 0}, (t_vec3){-1, 0, 0});
	const t_vec2	delta_uv1 = vec2_sub((t_vec2){0, 0}, (t_vec2){0, 1});
	const t_vec2	delta_uv2 = vec2_sub((t_vec2){1, 0}, (t_vec2){0, 1});
	const float		f = \
		1.0f / (delta_uv1.u * delta_uv2.v - delta_uv2.u * delta_uv1.v);

	t->x = f * (delta_uv2.v * edge1.x - delta_uv1.v * edge2.x);
	t->y = f * (delta_uv2.v * edge1.y - delta_uv1.v * edge2.y);
	t->z = f * (delta_uv2.v * edge1.z - delta_uv1.v * edge2.z);
	b->x = f * (-delta_uv2.u * edge1.x + delta_uv1.u * edge2.x);
	b->y = f * (-delta_uv2.u * edge1.y + delta_uv1.u * edge2.y);
	b->z = f * (-delta_uv2.u * edge1.z + delta_uv1.u * edge2.z);
}

t_vec3	matrix_mul_vec3(t_vec3 t, t_vec3 b, t_vec3 n, t_vec3 normal_map)
{
	return ((t_vec3){
		.x = t.x * normal_map.x + b.x * normal_map.y + n.x * normal_map.z,
		.y = t.y * normal_map.x + b.y * normal_map.y + n.y * normal_map.z,
		.z = t.z * normal_map.x + b.z * normal_map.y + n.z * normal_map.z
	});
}
