/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:11:26 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/07/26 23:46:07 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "hittable.h"
#include "libft.h"
#include "ray.h"
#include "vec3.h"
#include <stdlib.h>

/**
 * Sets the hit record normal vector.
 * NOTE: the parameter `outward_normal` is assumed to have unit length.
 */
void	set_face_normal(t_hit_record *rec, t_ray const *ray, \
	t_vec3 outward_normal)
{
	rec->front_face = vec3_dot(ray->direction, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = vec3_mul(outward_normal, -1);
}

t_hittable_list	*init_hittable_list(int capacity)
{
	t_hittable_list	*list;

	list = (t_hittable_list *)malloc(sizeof(t_hittable_list));
	if (!list)
		error_exit("Failed to allocate memory for hittable list");
	list->objects = (t_hittable **)malloc(sizeof(t_hittable *) * capacity);
	if (!list->objects)
		error_exit("Failed to allocate memory for hittable list");
	ft_memset(list->objects, 0, sizeof(t_hittable *) * capacity);
	list->size = 0;
	list->capacity = capacity;
	return (list);
}

void	add_hittable_list(t_hittable_list *list, t_hittable *object)
{
	t_hittable	**tmp;

	if (list->size >= list->capacity)
	{
		list->capacity *= 2;
		tmp = list->objects;
		list->objects = malloc(sizeof(t_hittable *) * list->capacity);
		if (!list->objects)
			error_exit("Failed to allocate memory for hittable list");
		ft_memcpy(list->objects, tmp, sizeof(t_hittable *) * list->size);
		free(tmp);
		tmp = NULL;
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

t_bool	hit_shapes(t_hittable_list *list, t_ray const *ray, \
	t_collision t, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	tmp;
	t_hit_func		hit_func;
	int				closest_so_far;
	int				i;

	closest_so_far = t.max;
	hit_anything = FALSE;
	i = 0;
	while (i < list->size)
	{
		hit_func = list->objects[i]->hit;
		if (hit_func(list->objects[i], ray, \
			(t_collision){t.min, closest_so_far}, &tmp))
		{
			hit_anything = TRUE;
			closest_so_far = tmp.t;
			*rec = tmp;
		}
		i++;
	}
	return (hit_anything);
}
