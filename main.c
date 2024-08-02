/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/03 00:03:07 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "key_hook.h"
#include "mlx.h"
#include <stdlib.h>

void	init_image(void *mlx, t_img *img);
void	init_world(t_hit_lst *world, t_cam *cam, char *filename);
void	init_viewport(t_img *img, t_cam *camera, t_vw *viewport);

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (EXIT_SUCCESS);
}
