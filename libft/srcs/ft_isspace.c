/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:40:31 by jeongwpa          #+#    #+#             */
/*   Updated: 2024/08/06 18:40:32 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	const char	*spaces = " \t\n\v\f\r";
	int			i;

	i = 0;
	while (spaces[i])
	{
		if (c == spaces[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}
