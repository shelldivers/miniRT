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
#include "error.h"

void	parse_ambient(char const *line, t_cam *cam, t_hit_lst *world)
{
	(void)line;
	(void)cam;
	(void)world;
}

/**
 * @brief parse camera line: <identifier> <view_point> <normal_vector> <FOV>
 * @param line	"C	-50.0,0,20	0,0,1	70"
 * @param cam	pointer to the camera
 * @param world	pointer to the world
 * @return	void
 */
void	parse_camera(char const *line, t_cam *cam)
{
	line++;
	skip_spaces(&line);
	cam->view_point = parse_vec3(line);
	move_to_next_param(&line);
	cam->normal = parse_vec3(line);
	move_to_next_param(&line);
	cam->fov = ft_strtoi(line, (char **)&line);
	must_be_last_number(line);
	if (cam->fov < 0 || cam->fov > 180)
		error_exit(ERROR_INVALID_FOV);
}

void	parse_light(char const *line, t_cam *cam, t_hit_lst *world)
{
	(void)line;
	(void)cam;
	(void)world;
}
