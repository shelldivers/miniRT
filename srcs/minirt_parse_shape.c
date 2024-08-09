/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:01:08 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 23:19:34 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include "libft.h"
#include "shape/plane.h"
#include "shape/sphere.h"
#include "shape/cylinder.h"

/**
 * @brief parse plane line: <identifier> <center> <normal> <color>
 * @warning line and world must not be NULL
 * @param line		"pl	0,0,20	0,1,0	255,255,255"
 * @param world 	pointer to the world
 * @return void
 */
void	parse_plane(char const *line, t_hit_lst *world)
{
	t_hit		*new_obj;
	t_plane		data;

	line += 2;
	must_numuric_and_comma(line);
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.normal = parse_vec3(line);
	move_to_next_param(&line);
	data.color = parse_vec3(line);
	must_be_valid_color(data.color);
	must_be_last_vec3(line);
	new_obj = (t_hit *)init_plane(data);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(world, new_obj);
}

/**
 * @brief parse sphere line: <identifier> <center> <diameter> <color>
 * @warning line and world must not be NULL
 * @param line		"sp	0,0,20	10	255,255,255"
 * @param world 	pointer to the world
 * @return void
 */
void	parse_sphere(char const *line, t_hit_lst *world)
{
	t_hit		*new_obj;
	t_sphere	data;
	char		*end_ptr;

	line += 2;
	must_numuric_and_comma(line);
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.radius = ft_strtof(line, &end_ptr) / 2;
	if (!ft_isspace(*end_ptr))
		error_exit(ERROR_INVALID_PARAM);
	move_to_next_param(&line);
	data.color = parse_vec3(line);
	must_be_valid_color(data.color);
	must_be_last_vec3(line);
	new_obj = (t_hit *)init_sphere(data);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(world, new_obj);
}

/**
 * @brief parse cylinder line:
 *        <identifier> <center> <normal> <diameter> <height> <color>
 * @warning line and world must not be NULL
 * @param line		"cy	0,0,20	0,1,0	10.2	10.4	255,255,255"
 * @param world 	pointer to the world
 * @return void
 */
void	parse_cylinder(char const *line, t_hit_lst *world)
{
	t_hit		*new_obj;
	t_cylinder	data;

	line += 2;
	must_numuric_and_comma(line);
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.normal = parse_vec3(line);
	move_to_next_param(&line);
	data.diameter = ft_strtof(line, (char **)&line);
	if (!ft_isspace(*line))
		error_exit(ERROR_INVALID_PARAM);
	move_to_next_param(&line);
	data.height = ft_strtof(line, (char **)&line);
	if (!ft_isspace(*line))
		error_exit(ERROR_INVALID_PARAM);
	move_to_next_param(&line);
	data.color = parse_vec3(line);
	must_be_valid_color(data.color);
	must_be_last_vec3(line);
	new_obj = (t_hit *)init_cylinder(data);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(world, new_obj);
}
