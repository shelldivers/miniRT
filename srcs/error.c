/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:34:38 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/25 22:44:26 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf.h"
#include <stdlib.h>

void	error_exit(char *message)
{
    ft_dprintf(2, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}