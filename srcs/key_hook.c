/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:55:15 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/03 00:38:27 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"
#include "minirt.h"
#include "mlx.h"
#include <stdlib.h>

int	key_press(int keycode, t_rt *rt)
{
	if (keycode == KEY_ESC)
		destroy_minirt(rt);
	return (0);
}

int	destroy_minirt(t_rt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	exit(EXIT_SUCCESS);
}
