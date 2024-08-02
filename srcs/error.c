/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:03:46 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/03 00:06:32 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	error_exit(char *message)
{
	ft_dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(EXIT_FAILURE);
}
