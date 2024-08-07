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
#include "libft.h"
#include "get_next_line.h"

void	parse_rtfile(int fd, t_cam *cam, t_hit_lst **world)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == 'A' && ft_isspace(line[1]))
			parse_ambient(line + 1, cam, world);
		else if (line[0] == 'C' && ft_isspace(line[1]))
			parse_camera(line + 1, cam);
		else if (line[0] == 'L' && ft_isspace(line[1]))
			parse_light(line + 1, cam, world);
		else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
			parse_plane(line + 2, cam, world);
		else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
			parse_sphere(line + 2, cam, world);
		else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
			parse_cylinder(line + 2, cam, world);
		else
			error_exit(ERROR_INVALID_IDENTIFIER);
		free(line);
	}
}
