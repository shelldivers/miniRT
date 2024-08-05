/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/03 00:44:12 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "key_hook.h"
#include "minirt.h"
#include "mlx.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_rt	rt;
	t_img	img;
	t_cam	cam;
	t_vw	vw;

	if (argc != 2)
		error_exit(ERROR_USAGE);
	init_mlx(&rt, &img);
	init_world(&cam, &rt.world, argv[1]);
	init_viewport(&img, &cam, &vw);
	ray_tracing(&img, &cam, &vw, rt.world);
	mlx_put_image_to_window(rt.mlx, rt.win, img.ptr, 0, 0);
	mlx_hook(rt.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &rt);
	mlx_hook(rt.win, X_EVENT_DESTROY, 0L, destroy_minirt, &rt);
	mlx_loop(rt.mlx);
	return (EXIT_SUCCESS);
}
