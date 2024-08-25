/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:38:33 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/25 15:39:11 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include <sys/time.h>
#include <unistd.h>

int	render_into_window(t_rt *rt)
{
	struct timeval	tv;
	static long		ts;
	long			te;

	gettimeofday(&tv, NULL);
	te = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (ts == 0)
		ts = te;
	if (te - ts > 50)
	{
		mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
		usleep(1000);
		ts = te;
	}
	return (0);
}
