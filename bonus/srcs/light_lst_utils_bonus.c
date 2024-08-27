/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_lst_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:47:08 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/27 18:53:34 by jiwojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reflection_bonus.h"
#include "error_bonus.h"
#include "libft.h"

t_light_lst	*init_light_list(int capacity)
{
	t_light_lst	*list;

	list = (t_light_lst *)malloc(sizeof(t_light_lst));
	if (!list)
		error_exit(ERROR_MALLOC);
	list->objects = (t_light **)malloc(sizeof(t_light *) * capacity);
	if (!list->objects)
		error_exit(ERROR_MALLOC);
	ft_memset(list->objects, 0, sizeof(t_light *) * capacity);
	list->size = 0;
	list->capacity = capacity;
	return (list);
}

void	add_light_list(t_light_lst *list, t_light *light)
{
	t_light	**tmp;

	if (list->size >= list->capacity)
	{
		list->capacity *= 2;
		tmp = list->objects;
		list->objects = malloc(sizeof(t_light *) * list->capacity);
		if (!list->objects)
			error_exit(ERROR_MALLOC);
		ft_memcpy(list->objects, tmp, sizeof(t_light *) * list->size);
		free(tmp);
		tmp = NULL;
	}
	list->objects[list->size++] = light;
}

void	clear_light_list(t_light_lst *list)
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
