/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:55:56 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/16 12:06:21 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_join;
	int		s1_len;
	int		s2_len;
	int		counter;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_join = malloc(s1_len + s2_len + 1);
	counter = 0;
	if (str_join == NULL)
		return (NULL);
	while (s1 && s1[counter])
	{
		str_join[counter] = s1[counter];
		counter++;
	}
	counter = 0;
	while (s2 && s2[counter])
	{
		str_join[s1_len + counter] = s2[counter];
		counter ++;
	}
	str_join[s1_len + s2_len] = '\0';
	return (str_join);
}
