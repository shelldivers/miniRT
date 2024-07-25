/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:25:12 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 00:35:27 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_LIST_H
# define HITTABLE_LIST_H

# include "hittable.h"

typedef struct s_hittable_list
{
	t_hittable		**objects;
	int				size;
	int				capacity;
}	t_hittable_list;

t_hittable_list	*init_hittable_list(int capacity);
void			add_hittable_list(t_hittable_list *list, t_hittable *object);
void			clear_hittable_list(t_hittable_list *list);

#endif
