/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:55:52 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/01 16:55:54 by jeongwpa         ###   ########.fr       */
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
# include "hittable.h"

typedef struct s_rt
{
	void			*mlx;
	void			*win;
	t_hit_lst		*world;
}	t_rt;

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

void	ray_tracing(t_img *img, t_cam *cam, t_vw *vw, t_hit_lst *world);

#endif
