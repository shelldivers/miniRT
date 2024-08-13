/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:55:52 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/13 23:49:04 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY 17
# define KEY_ESC 53
# define FLOAT_MAX 3.402823466e+38F
# define FLOAT_MIN 1.175494351e-38F

# include "vec3.h"
# include "camera.h"
# include "reflection.h"
# include "shape/hittable.h"

typedef struct s_data
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	t_data	data;
	int		width;
	int		height;
}	t_img;

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

// minirt_parser_world.c
typedef void	(*t_parse_func)(char const *line, t_rt *rt);

typedef struct s_parser
{
	char			*identifier;
	t_parse_func	func;
}	t_parser;

// minirt.c
void	ray_tracing(t_rt *rt);

// minirt_utils.c
void	init_mlx(t_rt *rt, t_img *img);
void	init_viewport(t_img *img, t_camera *camera, t_viewport *viewport);

// minirt_parse_world.c
void	init_world(t_rt *rt, char const *filename);
void	must_be_rt_extension(char const *filename);
void	parse_rtfile(int fd, t_rt *rt);
void	dispatch_line(char const *line, t_rt *rt);

// minirt_parse_scene.c
void	parse_ambient(char const *line, t_rt *rt);
void	parse_camera(char const *line, t_rt *rt);
void	parse_light(char const *line, t_rt *rt);

// minirt_parse_shape.c
void	parse_plane(char const *line, t_rt *rt);
void	parse_sphere(char const *line, t_rt *rt);
void	parse_cylinder(char const *line, t_rt *rt);
void	parse_cone(char const *line, t_rt *rt);

// minirt_parse_utils.c
void	must_numuric_and_comma(char const *line);
void	move_to_next_param(char const **ptr);
void	skip_spaces(char const **ptr);
void	must_be_last_vec3(char const *line);
void	must_be_last_number(char const *line);

// minirt_parse_utils2.c
void	normalize_color_value(t_color *color);
void	must_be_valid_normal(t_vec3 normal);
void	must_be_valid_ratio(float ratio);
void	must_have_no_remain(char const *line);

// minirt_parse_vec3.c
t_vec3	parse_vec3(char const *line);

#endif
