/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:33:57 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:52:50 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bonus.h"
#include "shape/hittable_bonus.h"
#include "ray_bonus.h"
#include "vec3_bonus.h"
#include "libft.h"
#include <stdlib.h>

t_hit_lst	*init_hittable_list(int capacity)
{
	t_hit_lst	*list;

	list = (t_hit_lst *)malloc(sizeof(t_hit_lst));
	if (!list)
		error_exit(ERROR_MALLOC);
	list->objects = (t_hit **)malloc(sizeof(t_hit *) * capacity);
	if (!list->objects)
		error_exit(ERROR_MALLOC);
	ft_memset(list->objects, 0, sizeof(t_hit *) * capacity);
	list->size = 0;
	list->capacity = capacity;
	return (list);
}

void	add_hittable_list(t_hit_lst *list, t_hit *object)
{
	t_hit	**tmp;

	if (list->size >= list->capacity)
	{
		list->capacity *= 2;
		tmp = list->objects;
		list->objects = malloc(sizeof(t_hit *) * list->capacity);
		if (!list->objects)
			error_exit(ERROR_MALLOC);
		ft_memcpy(list->objects, tmp, sizeof(t_hit *) * list->size);
		free(tmp);
		tmp = NULL;
	}
	list->objects[list->size++] = object;
}

void	clear_hittable_list(t_hit_lst *list)
{
	int	i;

	i = 0;
	while (i < list->size)
	{
		free(list->objects[i]);
		list->objects[i] = NULL;
		i++;
	}
	free(list->objects);
	list->objects = NULL;
	free(list);
	list = NULL;
}

t_bool	hit_shapes(t_hit_lst *list, t_ray const *ray, t_coll t, t_record *rec)
{
	t_bool		hit_anything;
	t_record	tmp;
	t_hit_func	hit_func;
	float		closest_so_far;
	int			i;

	closest_so_far = t.max;
	hit_anything = FALSE;
	i = 0;
	while (i < list->size)
	{
		hit_func = list->objects[i]->hit;
		if (hit_func(list->objects[i], ray, \
			(t_coll){t.min, closest_so_far}, &tmp))
		{
			hit_anything = TRUE;
			closest_so_far = tmp.t;
			if (rec)
				*rec = tmp;
		}
		i++;
	}
	return (hit_anything);
}
