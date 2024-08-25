/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/25 11:13:38 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "minirt.h"
#include "mlx_hook.h"
#include "mlx.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_thread_rt	*thread_rt;
	t_rt		*rt;

	if (argc != 2)
		error_exit(ERROR_USAGE);
	srand(time(NULL));
	rt = (t_rt *)malloc(sizeof(t_rt));
	if (!rt)
		error_exit(ERROR_MALLOC);
	init_mlx(rt, &rt->img);
	init_world(rt, argv[1]);
	init_viewport(rt);
	ray_tracing(rt);
	thread_rt = ray_tracing_thread_controller(rt);
	mlx_hook(rt->win, X_EVENT_KEY_PRESS, 1L << 0, key_press, thread_rt);
	mlx_hook(rt->win, X_EVENT_DESTROY, 0L, destroy_minirt, thread_rt);
	mlx_loop_hook(rt->mlx, render_into_window, rt);
	mlx_loop(rt->mlx);
	return (EXIT_SUCCESS);
}
