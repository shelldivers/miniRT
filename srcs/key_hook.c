/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:17:52 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/25 23:27:36 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"
#include "mlx.h"
#include <stdlib.h>

int	key_press(int keycode, t_minirt *rt)
{
	if (keycode == KEY_ESC)
        destroy_minirt(rt);
	return (0);
}

int destroy_minirt(t_minirt *rt)
{
    mlx_destroy_window(rt->mlx, rt->win);
    exit(0);
}
