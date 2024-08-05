/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:34:19 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/05 19:34:20 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "minirt.h"
#include <fcntl.h>

void	init_world(t_cam *cam, t_hit_lst **world, char *filename)
{
	t_hit	*shape;
	int		fd;

	(void)filename;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(ERROR_OPEN_FILE);
	// TODO: stash
	cam->view_point = (t_vec3){0, 0, 0};
	cam->normal = (t_vec3){0, 0, 0};
	cam->fov = 70;
	*world = init_hittable_list(10);
	if (!*world)
		error_exit("init_hittable_list() failed");
	shape = (t_hit *)init_sphere((t_vec3){0, 0, -1}, 0.5, (t_color){1, 0, 0});
	add_hittable_list(*world, shape);
}


