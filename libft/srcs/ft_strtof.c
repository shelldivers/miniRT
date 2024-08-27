/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:29:37 by jeongwpa          #+#    #+#             */
/*   Updated: 2023/10/11 11:29:38 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_powf(int n);
static double	get_n_flag(char c);

float	ft_strtof(const char *str, char **end_ptr)
{
	double	ac;
	double	n_flag;
	double	decimal;

	ac = 0.0;
	while (ft_isspace(*str))
		str++;
	n_flag = 1.0;
	if (*str == '-' || *str == '+')
		n_flag = get_n_flag(*str++);
	while (ft_isdigit(*str))
		ac = ac * 10.0 + (*str++ - '0') * n_flag;
	if (*str == '.')
		str++;
	decimal = 0;
	while (ft_isdigit(*str))
	{
		ac = ac * 10.0 + (*str++ - '0') * n_flag;
		decimal += 1.0;
	}
	ac /= ft_powf(decimal);
	if (end_ptr)
		*end_ptr = (char *)str;
	return (ac);
}

double	get_n_flag(char c)
{
	if (c == '-')
		return (-1.0);
	return (1.0);
}

static double	ft_powf(int n)
{
	double	ret;

	ret = 1.0;
	while (n--)
		ret *= 10.0;
	return (ret);
}
