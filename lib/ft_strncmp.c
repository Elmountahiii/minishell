/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:33:17 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 22:48:07 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	t;

	t = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((s1[t] != '\0' || s2[t] != '\0') && t < n)
	{
		if (s1[t] != s2[t])
		{
			return ((unsigned char)s1[t] - (unsigned char)s2[t]);
		}
		t ++;
	}
	return (0);
}
