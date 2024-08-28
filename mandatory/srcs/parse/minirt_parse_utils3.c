/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:51:30 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/28 00:13:58 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"

void	must_be_positive(float value)
{
	if (value <= 0)
		error_exit(ERROR_INVALID_PARAM);
}

void	must_have_valid_extension(char const *filename, char const *extension)
{
	char	*pos;
	char	*basename;

	basename = ft_strrchr(filename, '/');
	if (basename)
		basename++;
	else
		basename = (char *)filename;
	if (*basename == '.')
		error_exit(ERROR_INVALID_EXTENSION);
	pos = ft_strrchr(filename, '.');
	if (!pos)
		error_exit(ERROR_INVALID_EXTENSION);
	if (ft_strcmp(pos, (const char *)extension))
		error_exit(ERROR_INVALID_EXTENSION);
}

/**
 * @brief substr filename from line
 * @warning must free the return value
 * @param line	"-t resources/42.xpm"
 * @return char*	filename 
 */
char	*substr_filename(char const *line)
{
	const char	*pos;
	char		*filename;

	pos = line;
	while (*pos && !ft_isspace(*pos))
		pos++;
	filename = ft_substr(line, 0, pos - line);
	if (!filename)
		error_exit(ERROR_MALLOC);
	return (filename);
}
