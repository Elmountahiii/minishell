/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_partv1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:59:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/01/17 15:56:09 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_p(int len, void *adr, int *counter)
{
	unsigned long	address;
	int				width;
	int				i;
	int				count;

	address = (unsigned long) adr;
	width = hex_len(address) + 2;
	count = 0;
	i = 0;
	if (len > width)
	{
		while (i < (len - width))
		{
			count += put_char(' ');
			i++;
		}
	}
	count += print_address(adr);
	(*counter)++;
	return (count);
}

int	handle_c(int len, char c, int *counter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (len > 1)
	{
		while (i < (len - 1))
		{
			count += put_char(' ');
			i ++;
		}
	}
	count += put_char(c);
	(*counter)++;
	return (count);
}
