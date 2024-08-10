/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:11:34 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/10 02:13:12 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"
#include "ft_bool.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

static void		dispatch_line(char const *line, t_cam *cam, t_hit_lst *world);
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
			dispatch_line(line, cam, world);
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

void	dispatch_line(char const *line, t_cam *cam, t_hit_lst *world)
{
	int				i;
	int				identifier_length;
	const t_parser	parsers[] = {
	{"A", parse_ambient}, {"C", parse_camera}, {"L", parse_light},
	{"pl", parse_plane}, {"sp", parse_sphere}, {"cy", parse_cylinder},
	{NULL, NULL}};

	i = 0;
	while (parsers[i].identifier)
	{
		identifier_length = ft_strlen(parsers[i].identifier);
		if (!ft_strncmp(line, parsers[i].identifier, identifier_length)
			&& ft_isspace(line[identifier_length]))
		{
			parsers[i].func(line, cam, world);
			return ;
		}
		i++;
	}
	error_exit(ERROR_INVALID_IDENTIFIER);
}