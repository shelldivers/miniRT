/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:37:45 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/25 10:57:08 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HOOK_H
# define MLX_HOOK_H

# include "minirt.h"

// key_hook.c
int	key_press(int keycode, t_thread_rt *thread_rt);
int	destroy_minirt(t_thread_rt *thread_rt);

// loop_hook.c
int	render_into_window(t_rt *rt);

#endif
