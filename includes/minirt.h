/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:55:52 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/26 01:43:05 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1024
# define HEIGHT 576
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY 17
# define KEY_ESC 53
# define FLOAT_MAX 3.402823466e+38F
# define FLOAT_MIN 1.175494351e-38F
# define EPSILON 1e-6
# define COLOR_THRESHOLD 1e-2
# define XPM_EXTENSION ".xpm"
# define RT_EXTENSION ".rt"
# define SAMPLE_PER_PIXEL 100
# define THREAD 32
# ifndef PRE_PROCESSING
#  define PRE_PROCESSING FALSE
# endif

# include "vec3.h"
# include "image.h"
# include "camera.h"
# include "reflection.h"
# include "shape/hittable.h"
# include <pthread.h>

typedef struct s_rt
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_camera		cam;
	t_viewport		vw;
	t_ambient		ambient;
	t_light_lst		*lights;
	t_hit_lst		*world;
}	t_rt;

typedef struct s_thread_rt
{
	pthread_t	thread;
	t_rt		*rt;
	int			thread_id;
}	t_thread_rt;

// minirt_parser_world.c
typedef void	(*t_parse_func)(char const *line, t_rt *rt);

typedef struct s_parser
{
	char			*identifier;
	t_parse_func	func;
}	t_parser;

// minirt.c
void				ray_tracing(t_rt *rt);

// minirt_async.c
t_thread_rt			*ray_tracing_thread_controller(t_rt *rt);
t_thread_rt			*ray_tracing_thread_create(t_rt *rt);
void				ray_tracing_thread_destroy(t_thread_rt *thread_rt);
void				ray_tracing_async(t_thread_rt *thread_rt);

// minirt_color.c
t_color				ray_color(t_rt *rt, t_ray *ray);
t_color				get_phong_reflection_color(t_rt *rt, t_record *rec);
t_color				get_anti_aliased_color(\
	t_rt *rt, t_ray ray, int wid, int hei);
t_bool				is_tolerable(t_color c, t_color a, int s);

#endif
