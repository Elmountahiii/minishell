/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:54:23 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/27 11:55:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strnstr(char *haystack, char *needle, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && haystack[i + j] == needle[j]
			&& i + j < len)
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *) &haystack[i]);
		}
		i ++;
	}
	return (NULL);
}
