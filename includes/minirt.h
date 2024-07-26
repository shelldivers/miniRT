/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:30 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 23:13:28 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY 17
# define KEY_ESC 53
# define FLOAT_MAX 3.40282347e+38F
# define FLOAT_MIN 1.17549435e-38F

# include "camera.h"
# include "hittable.h"

typedef struct s_minirt
{
	void			*mlx;
	void			*win;
	t_hittable_list	*world;
}	t_minirt;

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

void	init_image(void *mlx, t_img *img);
void	init_viewport(t_img *img, t_camera *camera, t_viewport *viewport);
void	put_color(t_img *img, int x, int y, unsigned int color);
t_color	ray_color(t_ray const *ray, t_hittable_list *world);;

#endif
