/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:23:55 by yel-moun          #+#    #+#             */
/*   Updated: 2024/01/18 11:55:15 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_format(char format)
{
	if (format == 'x' || format == 'X' || format == 'd' || format == 'i')
		return (1);
	if (format == 's' || format == 'c' || format == 'u' || format == 'p')
		return (1);
	if (format == '%')
		return (1);
	if (is_bouns(format) || is_number(format))
		return (1);
	return (0);
}

int	handle_formats(const char *format, va_list args, int *i)
{
	int	count;

	count = 0;
	if (is_bouns(format[*i]) || is_number(format[*i]))
	{
		count += handle_bonus(i, format, args);
		return (count);
	}
	if (format[*i] == 'X' || format[*i] == 'x')
		count += put_hex(va_arg(args, unsigned int), format[*i]);
	if (format[*i] == 'd' || format[*i] == 'i')
		count += put_nbr(va_arg(args, int));
	if (format[*i] == 's')
		count += put_str(va_arg(args, char *));
	if (format[*i] == '%')
		count += put_char('%');
	if (format[*i] == 'c')
		count += put_char(va_arg(args, int));
	if (format[*i] == 'u')
		count += put_nbr_u(va_arg(args, unsigned int));
	if (format[*i] == 'p')
		count += print_address(va_arg(args, void *));
	if (is_format(format[*i]))
		(*i)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	if (write(1, 0, 0) == -1)
		return (-1);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] && is_format(format[i]))
				count += handle_formats(format, args, &i);
		}
		else
			count += put_char(format[i++]);
	}
	va_end(args);
	return (count);
}
