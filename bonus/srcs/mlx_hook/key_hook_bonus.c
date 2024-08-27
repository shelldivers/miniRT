/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:55:15 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:50:08 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_bonus.h"
#include "minirt_bonus.h"
#include "mlx.h"
#include <stdlib.h>

int	key_press(int keycode, t_thread_rt *thread_rt)
{
	if (keycode == KEY_ESC)
		destroy_minirt(thread_rt);
	return (0);
}

int	destroy_minirt(t_thread_rt *thread_rt)
{
	t_rt	*rt;

	rt = thread_rt->rt;
	ray_tracing_thread_destroy(thread_rt);
	mlx_destroy_window(rt->mlx, rt->win);
	exit(EXIT_SUCCESS);
}
