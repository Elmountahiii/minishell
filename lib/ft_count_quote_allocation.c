/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_quote_allocation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:00:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/07 12:02:35 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_count_quote_allocation(char *str, int *start)
{
	int		i;
	char	sign;

	i = 0;
	sign = str[(*start)];
	(*start)++;
	while (str[(*start) + i] && str[(*start) + i] != sign)
		i ++;
	return (i);
}
