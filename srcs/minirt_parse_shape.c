/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:01:08 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/11 02:05:51 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include "libft.h"
#include "camera.h"
#include "shape/plane.h"
#include "shape/sphere.h"
#include "shape/cylinder.h"

static void	must_have_no_remain(char const *line);

/**
 * @brief parse plane line: <identifier> <center> <normal> <color>
 * @warning line and world must not be NULL
 * @param line		"pl	0,0,20	0,1,0	255,255,255"
 * @param world 	pointer to the world
 * @return void
 */
void	parse_plane(char const *line, t_camera *cam, t_hit_lst *world)
{
	t_hit		*new_obj;
	t_plane		data;

	(void)cam;
	line += 2;
	must_numuric_and_comma(line);
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.normal = parse_vec3(line);
	move_to_next_param(&line);
	data.color = parse_vec3(line);
	normalize_color_value(&data.color);
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
void	parse_sphere(char const *line, t_camera *cam, t_hit_lst *world)
{
	t_hit		*new_obj;
	t_sphere	data;

	(void)cam;
	line += 2;
	must_numuric_and_comma(line);
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.radius = ft_strtof(line, (char **)&line) / 2;
	must_have_no_remain(line);
	move_to_next_param(&line);
	data.color = parse_vec3(line);
	normalize_color_value(&data.color);
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
void	parse_cylinder(char const *line, t_camera *cam, t_hit_lst *world)
{
	t_hit		*new_obj;
	t_cylinder	data;

	(void)cam;
	line += 2;
	must_numuric_and_comma(line);
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.normal = parse_vec3(line);
	move_to_next_param(&line);
	data.diameter = ft_strtof(line, (char **)&line);
	must_have_no_remain(line);
	move_to_next_param(&line);
	data.height = ft_strtof(line, (char **)&line);
	must_have_no_remain(line);
	move_to_next_param(&line);
	data.color = parse_vec3(line);
	normalize_color_value(&data.color);
	must_be_last_vec3(line);
	new_obj = (t_hit *)init_cylinder(data);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(world, new_obj);
}

void	must_have_no_remain(char const *line)
{
	if (!ft_isspace(*line))
		error_exit(ERROR_INVALID_PARAM);
}
