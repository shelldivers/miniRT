/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:01:08 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/06 19:01:09 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include "libft.h"
#include "shape/sphere.h"

void	parse_plane(char *line, t_cam *cam, t_hit_lst **world)
{
	(void)line;
	(void)cam;
	(void)world;
}

/**
 * @brief parse sphere line: <identifier> <center> <diameter> <color>
 * @remark it is assumed that identifier(sp) is already parsed
 * @param line		"sp	0,0,20	10	255,255,255"
 * @param cam		pointer to the camera
 * @param world 	pointer to the world
 * @return void
 */
void	parse_sphere(char *line, t_cam *cam, t_hit_lst **world)
{
	t_sphere	*sphere;
	t_hit_lst	*new;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		error_exit(ERROR_MALLOC);
	ft_memset(sphere, 0, sizeof(t_sphere));
	while (*line && ft_isspace(*line))
		++line;
	sphere->center = parse_vec3(line);
	while (*line && !ft_isspace(*line))
		++line;
	while (*line && ft_isspace(*line))
		++line;
	sphere->radius = ft_atof(line) / 2;
	while (*line && !ft_isspace(*line))
		++line;
	while (*line && ft_isspace(*line))
		++line;
	sphere->color = parse_vec3(line);
	sphere->parent.hit = hit_sphere;
	sphere->parent.shape = SPHERE;
	add_hittable_list(world, sphere);
}

void	parse_cylinder(char *line, t_cam *cam, t_hit_lst **world)
{
	(void)line;
	(void)cam;
	(void)world;
}
