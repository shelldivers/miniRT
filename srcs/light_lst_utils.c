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

t_light_lst	*init_light_list(void)
{
	t_light_lst	*list;

	list = (t_light_lst *)malloc(sizeof(t_light_lst));
	if (!list)
		error_exit(ERROR_MALLOC);
	list->light = NULL;
	list->next = NULL;
	return (list);
}
