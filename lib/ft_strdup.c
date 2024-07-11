/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:16:09 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/16 13:32:33 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*s2;

	len = ft_strlen(s1);
	s2 = malloc(len * sizeof(char) + 1);
	i = 0;
	if (s2 == NULL)
	{
		return (NULL);
	}
	while (s1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
