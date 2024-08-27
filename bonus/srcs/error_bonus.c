/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:03:46 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:46:40 by jiwojung         ###   ########.fr       */
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
