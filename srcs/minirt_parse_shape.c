/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:01:08 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 01:29:34 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include "libft.h"
#include "shape/plane.h"
#include "shape/sphere.h"

void	parse_plane(char *line, t_cam *cam, t_hit_lst **world)
{
	t_hit		*new_obj;
	t_point3	center;
	t_vec3		normal;
	t_color		color;

	while (*line && ft_isspace(*line))
		++line;
	center = parse_vec3(line);
	while (*line && !ft_isspace(*line))
		++line;
	while (*line && ft_isspace(*line))
		++line;
	normal = parse_vec3(line);
	while (*line && !ft_isspace(*line))
		++line;
	while (*line && ft_isspace(*line))
		++line;
	color = parse_vec3(line);
	new_obj = (t_hit *)init_plane(center, normal, color);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(*world, new_obj);
}

/**
 * @brief parse sphere line: <identifier> <center> <diameter> <color>
 * @remark it is assumed that identifier(sp) is already parsed
 * @param line		"sp	0,0,20	10	255,255,255"
 * @param cam		pointer to the camera
 * @param world 	pointer to the world
 * @return void
 */
void	parse_sphere(char *line, t_hit_lst **world)
{
	t_hit		*new_obj;
	t_point3	center;
	float		radius;
	t_color		color;

	while (*line && ft_isspace(*line))
		++line;
	center = parse_vec3(line);
	while (*line && !ft_isspace(*line))
		++line;
	while (*line && ft_isspace(*line))
		++line;
	radius = ft_atof(line) / 2;
	while (*line && !ft_isspace(*line))
		++line;
	while (*line && ft_isspace(*line))
		++line;
	color = parse_vec3(line);
	new_obj = (t_hit *)init_sphere(center, radius, color);
	if (!new_obj)
		error_exit(ERROR_MALLOC);
	add_hittable_list(*world, new_obj);
}

void	parse_cylinder(char *line, t_cam *cam, t_hit_lst **world)
{
	(void)line;
	(void)cam;
	(void)world;
}
