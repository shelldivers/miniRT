/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:00:59 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/06 19:01:02 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	parse_ambient(char *line, t_cam *cam, t_hit_lst **world)
{
	(void)line;
	(void)cam;
	(void)world;
}

/**
 *  @brief parse camera line: <identifier> <view_point> <normal_vector> <FOV>
 *  @param line		"C	-50.0,0,20	0,0,1	70"
 *  @param cam		pointer to the camera
 *  @param world	pointer to the world
 *  @return void
 */
void	parse_camera(char *line, t_cam *cam)
{
	while (*line && ft_isspace(*line))
		++line;
	cam->view_point = parse_vec3(line);
	while (*line && ft_isspace(*line))
		++line;
	cam->normal = parse_vec3(line);
	while (*line && ft_isspace(*line))
		++line;
	cam->fov = ft_atoi(line);
}

void	parse_light(char *line, t_cam *cam, t_hit_lst **world)
{
	(void)line;
	(void)cam;
	(void)world;
}
