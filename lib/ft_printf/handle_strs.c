/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:11:24 by yel-moun          #+#    #+#             */
/*   Updated: 2024/01/15 12:44:56 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(char c)
{
	int	count;

	count = 0;
	count = write(1, &c, 1);
	return (count);
}

int	put_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		count = 6;
		return (count);
	}
	while (str[count])
	{
		put_char(str[count]);
		count ++;
	}
	return (count);
}
