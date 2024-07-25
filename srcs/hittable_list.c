/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:25:42 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 00:42:22 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"
#include "hittable_list.h"
#include "libft.h"
#include "error.h"
#include <stdlib.h>

t_hittable_list	*init_hittable_list(int capacity)
{
	t_hittable_list	*list;

	list->objects = (t_hittable **)malloc(sizeof(t_hittable *) * capacity);
	if (!list->objects)
		exit_error("Failed to allocate memory for hittable list");
	ft_memset(list->objects, 0, sizeof(t_hittable *) * capacity);
	list->capacity = capacity;
	return (list);
}

void	add_hittable_list(t_hittable_list *list, t_hittable *object)
{
	if (list->size >= list->capacity)
	{
		list->capacity *= 2;
		list->objects = (t_hittable **)ft_realloc(list->objects, sizeof(t_hittable *) * list->capacity);
		if (!list->objects)
			exit_error("Failed to reallocate memory for hittable list");
	}
	list->objects[list->size++] = object;
}

void	clear_hittable_list(t_hittable_list *list)
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

t_bool	hit_shapes(t_hittable_list *list, t_ray const *ray, float t_min, float t_max, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	tmp;
	int				i;
	int				closest_so_far;

	closest_so_far = t_max;
	hit_anything = FALSE;
	i = 0;
	while (i < list->size)
	{
		if (list->objects[i]->hit(list->objects[i], ray, t_min, closest_so_far, &tmp)) {
			hit_anything = TRUE;
			closest_so_far = tmp.t;
			*rec = tmp;
		}
		i++;
	}
	return (hit_anything);
}
