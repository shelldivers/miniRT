/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:41:02 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/08 21:19:57 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_USAGE "Usage: ./minirt [filename]"
# define ERROR_OPEN_FILE "Failed to open the file"
# define ERROR_INVALID_IDENTIFIER "Invalid identifier"
# define ERROR_MALLOC "Failed to allocate memory"
# define ERROR_INVALID_VEC3 "Invalid vec3 format"
# define ERROR_INVALID_PARAM "Invalid parameter format"
# define ERROR_INVALID_FOV "FOV must be between 0 and 180"
# define ERROR_INVALID_COLOR "Color must be between 0 and 255"
# define ERROR_INVALID_NORMAL "Normal must be between -1 and 1"
# define ERROR_INVALID_RATIO "Ratio must be between 0 and 1"

void	error_exit(char *message);

#endif
