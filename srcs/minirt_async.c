/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_async.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:44:58 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/25 02:49:24 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include <stdlib.h>
#include <pthread.h>

void	ray_tracing_thread_controller(t_rt *rt)
{
	t_thread_rt	*thread_rt;
	int			i;

	thread_rt = (t_thread_rt *)malloc(sizeof(t_thread_rt) * THREAD_COUNT);
	if (!thread_rt)
		error_exit(ERROR_MALLOC);
	i = 0;
	while (i < THREAD_COUNT)
	{
		thread_rt[i].rt = rt;
		thread_rt[i].thread_id = i;
		pthread_create(&thread_rt[i].thread, NULL, \
			(void *)ray_tracing_async, &thread_rt[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
	{
		pthread_join(thread_rt[i].thread, NULL);
		i++;
	}
}

void	ray_tracing_async(t_thread_rt *thread_rt)
{
	t_rt	*rt;
	t_ray	ray;
	int		height;
	int		width;
	t_color	color;

	rt = thread_rt->rt;
	height = 0;
	ray.origin = rt->cam.view_point;
	while (height < rt->img.height)
	{
		if (height % THREAD_COUNT != thread_rt->thread_id)
		{
			height++;
			continue ;
		}
		width = 0;
		while (width < rt->img.width)
		{
			color = get_anti_aliased_color(rt, ray, width, height);
			put_color(&(rt->img), width, height, color_to_int(color));
			width++;
		}
		height++;
	}
}
