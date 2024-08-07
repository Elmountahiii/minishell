/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:23:37 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/07 15:33:39 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_bouns(char c)
{
	if (c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	handle_x(char sign, int width, char format, unsigned long nbr)
{
	int	count;
	int	len;
	int	i;
	int	final_len;

	count = 0;
	i = 0;
	len = hex_len(nbr);
	final_len = width - len;
	if (sign == '#')
		final_len = width - len - 2;
	if (width > len)
		while (i++ < final_len)
			count += put_char(' ');
	if (sign == '#' && format == 'x' && nbr > 0)
		count += put_str("0x");
	if (sign == '#' && format == 'X' && nbr > 0)
		count += put_str("0X");
	count += put_hex(nbr, format);
	return (count);
}

int	handle_d_i(char sign, int nbr, int len, int *c)
{
	int	count;
	int	digit_count;
	int	i;
	int	width;

	count = 0;
	i = 0;
	digit_count = number_len(nbr);
	width = len - digit_count;
	if (len > digit_count)
	{
		if (sign == ' ' || sign == '+')
			width --;
		while (i++ < width)
			count += put_char(' ');
	}
	if (sign == ' ' && nbr >= 0)
		count += put_char(' ');
	if (sign == '+' && nbr >= 0)
		count += put_char('+');
	count += put_nbr(nbr);
	(*c)++;
	return (count);
}

int	handle_s(int nbr, char *str, int *c)
{
	int	count;
	int	len;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	if (nbr > len)
		while (i++ < (nbr - len))
			count += put_char(' ');
	count += put_str(str);
	(*c)++;
	return (count);
}

int	handle_bonus(int *i, const char *format, va_list args)
{
	char	sign;
	int		count;
	int		len;

	count = 0;
	sign = 'o';
	len = 0;
	get_sign(i, format, &len, &sign);
	if (format[*i] && format[*i] == '%')
		count += handle_c(len, '%', i);
	if (format[*i] && format[*i] == 's')
		count += handle_s(len, va_arg(args, char *), i);
	if (format[*i] && (format[*i] == 'x' || format[*i] == 'X'))
	{
		count += handle_x(sign, len, format[*i], va_arg(args, unsigned int));
		(*i)++;
	}
	if (format[*i] && (format[*i] == 'd' || format[*i] == 'i'))
		count += handle_d_i(sign, va_arg(args, int), len, i);
	if (format[*i] && format[*i] == 'c')
		count += handle_c(len, va_arg(args, int), i);
	if (format[*i] && (format[*i] == 'p'))
		count += handle_p(len, va_arg(args, void *), i);
	return (count);
}
