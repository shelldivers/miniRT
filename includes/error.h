/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:41:02 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/01 17:41:03 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_USAGE "Usage: ./minirt [filename]"
# define ERROR_OPEN_FILE "Failed to open the file"

void	error_exit(char *message);

#endif
