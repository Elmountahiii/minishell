/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:27:54 by yel-moun          #+#    #+#             */
/*   Updated: 2024/01/15 12:58:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned long nbr, char format)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbr == 0)
	{
		count += put_char('0');
		return (count);
	}
	if (nbr >= 16)
	{
		count += put_hex(nbr / 16, format);
	}
	count += put_char(base[nbr % 16]);
	return (count);
}

int	put_nbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += put_str("-2147483648");
		return (count);
	}
	if (nbr < 0)
	{
		count += put_char('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		count += put_nbr(nbr / 10);
	}
	count += put_char(nbr % 10 + 48);
	return (count);
}

int	put_nbr_u(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
	{
		count += put_nbr(nbr / 10);
	}
	count += put_char(nbr % 10 + 48);
	return (count);
}

int	print_address(void *adr)
{
	int				count;
	unsigned long	adresss;

	count = 0;
	adresss = (unsigned long) adr;
	if (!adr)
	{
		count += put_str("0x0");
		return (count);
	}
	count += put_str("0x");
	count += put_hex(adresss, 'x');
	return (count);
}

int	number_len(int number)
{
	int	count;

	count = 0;
	if (number == 0)
	{
		return (1);
	}
	if (number < 0)
	{
		number *= -1;
	}
	while (number != 0)
	{
		number = number / 10;
		count ++;
	}
	return (count);
}
