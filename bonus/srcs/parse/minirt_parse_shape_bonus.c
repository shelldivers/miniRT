/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_shape_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:01:08 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:51:07 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "parse_bonus.h"
#include "error_bonus.h"
#include "camera_bonus.h"
#include "shape/plane_bonus.h"
#include "shape/sphere_bonus.h"
#include "shape/cylinder_bonus.h"
#include "shape/cone_bonus.h"
#include "libft.h"

static void	validate_positive_and_move_next(char const **line, float data);

/**
 * @brief parse plane line: <identifier> <center> <normal> <color>
 * @param line	"pl	0,0,20	0,1,0	255,255,255"
 * @param rt	pointer to the raytracer
 * @return void
 */
void	parse_plane(char const *line, t_rt *rt)
{
	t_hit		*new_obj;
	t_plane		data;

	line += 2;
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.normal = parse_vec3(line);
	normalize_vec3(&data.normal);
	move_to_next_param(&line);
	data.parent.color = parse_vec3(line);
	normalize_color_value(&data.parent.color);
	data.parent.texture.enable = FALSE;
	if (has_texture(line))
		parse_texture(rt, &data.parent, &line);
	else
		must_be_last_vec3(line);
	new_obj = (t_hit *)init_plane(data);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(rt->world, new_obj);
}

/**
 * @brief parse sphere line: <identifier> <center> <diameter> <color>
 * @param line	"sp	0,0,20	10	255,255,255"
 * @param rt	pointer to the raytracer
 * @return void
 */
void	parse_sphere(char const *line, t_rt *rt)
{
	t_hit		*new_obj;
	t_sphere	data;

	line += 2;
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.radius = ft_strtof(line, (char **)&line) / 2;
	validate_positive_and_move_next(&line, data.radius);
	data.parent.color = parse_vec3(line);
	normalize_color_value(&data.parent.color);
	data.parent.texture.enable = FALSE;
	if (has_texture(line))
		parse_texture(rt, &data.parent, &line);
	else
		must_be_last_vec3(line);
	new_obj = (t_hit *)init_sphere(data);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(rt->world, new_obj);
}

/**
 * @brief parse cylinder line:
 *        <identifier> <center> <normal> <diameter> <height> <color>
 * @param line	"cy	0,0,20	0,1,0	10.2	10.4	255,255,255"
 * @param rt	pointer to the raytracer
 * @return void
 */
void	parse_cylinder(char const *line, t_rt *rt)
{
	t_hit		*new_obj;
	t_cylinder	data;

	line += 2;
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.normal = parse_vec3(line);
	normalize_vec3(&data.normal);
	move_to_next_param(&line);
	data.radius = ft_strtof(line, (char **)&line) / 2.0;
	validate_positive_and_move_next(&line, data.radius);
	data.height = ft_strtof(line, (char **)&line);
	validate_positive_and_move_next(&line, data.height);
	data.parent.color = parse_vec3(line);
	normalize_color_value(&data.parent.color);
	data.parent.texture.enable = FALSE;
	if (has_texture(line))
		parse_texture(rt, &data.parent, &line);
	else
		must_be_last_vec3(line);
	new_obj = (t_hit *)init_cylinder(data);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(rt->world, new_obj);
}

/**
 * @brief parse cone line:
 * 	      <identifier> <center> <normal> <diameter> <height> <color>
 * @warning line and world must not be NULL
 * @param line	"co	0,0,20	0,1,0	10.2	10.4	255,255,255"
 * @param rt	pointer to the raytracer
 * @return void
 */
void	parse_cone(char const *line, t_rt *rt)
{
	t_hit	*new_obj;
	t_cone	data;

	line += 2;
	skip_spaces(&line);
	data.center = parse_vec3(line);
	move_to_next_param(&line);
	data.normal = parse_vec3(line);
	normalize_vec3(&data.normal);
	move_to_next_param(&line);
	data.radius = ft_strtof(line, (char **)&line) / 2.0;
	validate_positive_and_move_next(&line, data.radius);
	data.height = ft_strtof(line, (char **)&line);
	validate_positive_and_move_next(&line, data.height);
	data.parent.color = parse_vec3(line);
	normalize_color_value(&data.parent.color);
	data.parent.texture.enable = FALSE;
	if (has_texture(line))
		parse_texture(rt, &data.parent, &line);
	else
		must_be_last_vec3(line);
	new_obj = (t_hit *)init_cone(data);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(rt->world, new_obj);
}

void	validate_positive_and_move_next(char const **line, float data)
{
	must_be_positive(data);
	must_have_no_remain(*line);
	move_to_next_param(line);
}