/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:11:34 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/10 01:47:38 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"
#include "ft_bool.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

static void		rtline_branch(char const *line, t_cam *cam, t_hit_lst *world);
static t_bool	is_not_blank(char const *line);

void	init_world(t_cam *cam, t_hit_lst *world, char *filename)
{
	int		fd;

	must_be_rt_extension(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(ERROR_OPEN_FILE);
	world = init_hittable_list(10);
	parse_rtfile(fd, cam, world);
}

void	must_be_rt_extension(char const *filename)
{
	char	*pos;

	if (*filename == '.')
		error_exit(ERROR_INVALID_IDENTIFIER);
	pos = ft_strrchr(filename, '.');
	if (ft_strcmp(pos, ".rt"))
		error_exit(ERROR_INVALID_IDENTIFIER);
}

void	parse_rtfile(int fd, t_cam *cam, t_hit_lst *world)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line && is_not_blank(line))
			rtline_branch(line, cam, world);
		free(line);
	}
}

t_bool	is_not_blank(char const *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (TRUE);
		line++;
	}
	return (FALSE);
}

void	rtline_branch(char const *line, t_cam *cam, t_hit_lst *world)
{
	if (line[0] == 'A' && ft_isspace(line[1]))
		parse_ambient(line, cam, world);
	else if (line[0] == 'C' && ft_isspace(line[1]))
		parse_camera(line, cam);
	else if (line[0] == 'L' && ft_isspace(line[1]))
		parse_light(line, cam, world);
	else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
		parse_plane(line, world);
	else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
		parse_sphere(line, world);
	else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
		parse_cylinder(line, world);
	else
		error_exit(ERROR_INVALID_IDENTIFIER);
}
