/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:47:08 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/12 15:47:09 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reflection.h"
#include "libft.h"
#include "error.h"

t_light_lst	*init_light_list(int capacity)
{
	t_light_lst	*list;

	list = (t_light_lst *)malloc(sizeof(t_light_lst));
	if (!list)
		error_exit(ERROR_MALLOC);
	list->lights = (t_light **)malloc(sizeof(t_light *) * capacity);
	if (!list->lights)
		error_exit(ERROR_MALLOC);
	ft_memset(list->lights, 0, sizeof(t_light *) * capacity);
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
		tmp = list->lights;
		list->lights = malloc(sizeof(t_light *) * list->capacity);
		if (!list->lights)
			error_exit(ERROR_MALLOC);
		ft_memcpy(list->lights, tmp, sizeof(t_light *) * list->size);
		free(tmp);
		tmp = NULL;
	}
	list->lights[list->size++] = light;
}

void	clear_light_list(t_light_lst *list)
{
	int	i;

	i = 0;
	while (i < list->size)
	{
		free(list->lights[i]);
		list->lights[i] = NULL;
		i++;
	}
	free(list->lights);
	list->lights = NULL;
	free(list);
	list = NULL;
}
