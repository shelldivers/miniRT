/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_async.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:44:58 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/25 11:30:55 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include <stdlib.h>
#include <pthread.h>

t_thread_rt	*ray_tracing_thread_controller(t_rt *rt)
{
	t_thread_rt	*thread_rt;
	int			i;

	thread_rt = (t_thread_rt *)malloc(sizeof(t_thread_rt) * THREAD);
	if (!thread_rt)
		error_exit(ERROR_MALLOC);
	i = 0;
	while (i < THREAD)
	{
		thread_rt[i].rt = rt;
		thread_rt[i].thread_id = i;
		pthread_create(&thread_rt[i].thread, NULL, \
			(void *)ray_tracing_async, &thread_rt[i]);
		i++;
	}
	return (thread_rt);
}

void	ray_tracing_thread_destroy(t_thread_rt *thread_rt)
{
	int	i;

	i = 0;
	while (i < THREAD)
	{
		pthread_cancel(thread_rt[i].thread);
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_join(thread_rt[i].thread, NULL);
		i++;
	}
}

void	ray_tracing_async(t_thread_rt *thread_rt)
{
	t_ray	ray;
	int		h;
	int		w;
	t_color	c;

	h = 0;
	ray.origin = thread_rt->rt->cam.view_point;
	while (h < thread_rt->rt->img.height)
	{
		if (h % THREAD != thread_rt->thread_id)
		{
			h++;
			continue ;
		}
		w = 0;
		while (w < thread_rt->rt->img.width)
		{
			pthread_testcancel();
			c = get_anti_aliased_color(thread_rt->rt, ray, w, h);
			put_color(&(thread_rt->rt->img), w, h, color_to_int(c));
			w++;
		}
		h++;
	}
}
