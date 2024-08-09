/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:34:19 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 22:42:39 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "minirt.h"
#include "libft.h"

void	must_be_rt_extension(char const *filename)
{
	char	*pos;

	if (*filename == '.')
		error_exit(ERROR_INVALID_IDENTIFIER);
	pos = ft_strrchr(filename, '.');
	if (ft_strcmp(pos, ".rt"))
		error_exit(ERROR_INVALID_IDENTIFIER);
}
