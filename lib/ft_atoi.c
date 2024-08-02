/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:10:53 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/02 17:48:49 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	is_tab(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' 
		|| c == '\f' || c == '\n')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	check;
	long long	n;
	int			sign;

	n = 0;
	sign = 1;
	while (is_tab(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		check = n;
		n = n * 10 + sign * (*str - 48);
		if (check > n && sign == 1)
			return (-1);
		else if (check < n && sign == -1)
			return (0);
		str++;
	}
	return ((int)n);
}
