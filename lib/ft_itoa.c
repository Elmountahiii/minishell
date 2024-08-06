/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:57:57 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/06 10:33:44 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

size_t	count_len(int nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		i ++;
		nb *= -1;
	}
	while (nb > 0)
	{
		i ++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;

	len = count_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	while (len-- && n > 0)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}