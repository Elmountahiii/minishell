/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:23:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/20 12:27:48 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoiv1(const char *str, int *c)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (((str[*c] >= 9 && str[*c] <= 13) || str[*c] == 32))
	{
		(*c)++;
	}
	if (str[*c] == '+' || str[*c] == '-')
	{
		if (str[*c] == '-')
			sign = -1;
		(*c)++;
	}
	while (str[*c] && is_number(str[*c]))
	{
		result = result * 10 + (str[*c] - 48);
		(*c)++;
	}
	return (result * sign);
}

int	hex_len(unsigned long number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 16;
		len++;
	}
	return (len);
}

void	get_sign(int *i, const char *format, int *len, char *sign)
{
	while (is_bouns(format[*i]) || is_number(format[*i]))
	{
		if (is_bouns(format[*i]))
		{
			if (*sign == '#' && format[*i] != '#' && !is_number(format[*i]))
				(*i)++;
			else if (*sign == '+' && format[*i] != '+'
				&& !is_number(format[*i]))
				(*i)++;
			else if (is_bouns(format[*i]))
				*sign = format[(*i)++];
		}
		if (is_number(format[*i]))
			*len = ft_atoiv1(format, i);
	}
}
