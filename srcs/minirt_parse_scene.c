/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:00:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/13 17:08:01 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"

void	parse_ambient(char const *line, t_rt *rt)
{
	line++;
	skip_spaces(&line);
	rt->ambient.ratio = ft_strtof(line, (char **)&line);
	must_have_no_remain(line);
	must_be_valid_ratio(rt->ambient.ratio);
	move_to_next_param(&line);
	rt->ambient.color = parse_vec3(line);
	normalize_color_value(&rt->ambient.color);
	must_be_last_vec3(line);
	rt->ambient.light = vec3_mul(rt->ambient.color, rt->ambient.ratio);
}

/**
 * @brief parse camera line: <identifier> <view_point> <normal_vector> <FOV>
 * @param line	"C	-50.0,0,20	0,0,1	70"
 * @param cam	pointer to the camera
 * @param world	pointer to the world
 * @return	void
 */
void	parse_camera(char const *line, t_rt *rt)
{
	line++;
	skip_spaces(&line);
	rt->cam.view_point = parse_vec3(line);
	move_to_next_param(&line);
	rt->cam.normal = parse_vec3(line);
	must_be_valid_normal(rt->cam.normal);
	move_to_next_param(&line);
	rt->cam.fov = ft_strtoi(line, (char **)&line);
	must_be_last_number(line);
	if (rt->cam.fov < 0 || rt->cam.fov > 180)
		error_exit(ERROR_INVALID_FOV);
}

void	parse_light(char const *line, t_rt *rt)
{
	t_light	*new_light;

	new_light = (t_light *)malloc(sizeof(t_light));
	if (!new_light)
		error_exit(ERROR_MALLOC);
	line++;
	skip_spaces(&line);
	new_light->center = parse_vec3(line);
	move_to_next_param(&line);
	new_light->ratio = ft_strtof(line, (char **)&line);
	must_have_no_remain(line);
	must_be_valid_ratio(new_light->ratio);
	move_to_next_param(&line);
	new_light->color = parse_vec3(line);
	normalize_color_value(&new_light->color);
	must_be_last_vec3(line);
	add_light_list(rt->lights, new_light);
}
