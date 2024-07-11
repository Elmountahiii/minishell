/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:38:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 14:00:15 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strchr(char *s, int c)
{
	int	i;
	int	length;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	while (i <= length)
	{
		if (s[i] == ((char)c))
		{
			return ((char *)&s[i]);
		}
		i ++;
	}
	return (NULL);
}
