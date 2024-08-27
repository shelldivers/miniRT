/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_world_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:11:34 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:51:46 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include "minirt_bonus.h"
#include "error_bonus.h"
#include "ft_bool.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_bool	is_not_blank(char const *line);

void	init_world(t_rt *rt, char const *filename)
{
	int			fd;

	must_be_rt_extension(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(ERROR_OPEN_FILE);
	rt->world = init_hittable_list(10);
	rt->lights = init_light_list(10);
	parse_rtfile(fd, rt);
	close(fd);
}

void	must_be_rt_extension(char const *filename)
{
	must_have_valid_extension(filename, RT_EXTENSION);
}

void	parse_rtfile(int fd, t_rt *rt)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line && is_not_blank(line))
			dispatch_line(line, rt);
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

void	dispatch_line(char const *line, t_rt *rt)
{
	int				i;
	int				identifier_length;
	const t_parser	parsers[] = {
	{"A", parse_ambient}, {"C", parse_camera}, {"L", parse_light},
	{"pl", parse_plane}, {"sp", parse_sphere}, {"cy", parse_cylinder},
	{"co", parse_cone}, {NULL, NULL}};

	i = 0;
	while (parsers[i].identifier)
	{
		identifier_length = ft_strlen(parsers[i].identifier);
		if (!ft_strncmp(line, parsers[i].identifier, identifier_length)
			&& ft_isspace(line[identifier_length]))
		{
			parsers[i].func(line, rt);
			return ;
		}
		i++;
	}
	error_exit(ERROR_INVALID_IDENTIFIER);
}
