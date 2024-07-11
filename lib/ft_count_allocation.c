/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_allocation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:36:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/07 12:10:23 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_count_allocation(char *str, int *start)
{
	int		i;

	i = 0;
	while (str[i + (*start)])
	{
		if (ft_is_quote(str[(*start)]))
		{
			i = ft_count_quote_allocation(str, start);
			break ;
		}
		else if (ft_is_space(str[i + (*start)]))
			break ;
		i ++;
	}
	return (i);
}
