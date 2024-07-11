/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:10:19 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/04 16:05:51 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_skip_quotes(char *str, int index)
{
	int	sign;

	sign = str[index];
	index++;
	while (str[index] && str[index] != sign)
		index ++;
	if (ft_is_quote(str[index]))
		index ++;
	return (index);
}
