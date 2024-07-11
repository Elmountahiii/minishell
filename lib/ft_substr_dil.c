/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_dil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:58:56 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/29 13:00:04 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_substr_dil(char *str, int start, char dil)
{
	int		len;
	int		end;
	char	*sub;
	int		i;

	i = 0;
	while (str[i + start])
	{
		if (str[i + start] == dil)
			break ;
		i ++;
	}
	end = start + i;
	len = end - start;
	i = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (str[i + start] && i < len)
	{
		sub[i] = str[i + start];
		i ++;
	}
	sub[i] = '\0';
	return (sub);
}
