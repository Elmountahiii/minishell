/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:39:05 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/02 16:41:44 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**ft_split_dil(char *str, char dil)
{
	char	**split;
	int		index;
	int		i;

	split = malloc(sizeof(char *) * (ft_count_words_dil(str, dil) + 1));
	if (!split)
		return (NULL);
	i = 0;
	index = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != dil)
		{
			split[index] = ft_substr_dil(str, i, dil);
			if (!split[index])
				return (ft_free_split(split, index), NULL);
			while (str[i] && str[i] != dil)
				i ++;
			index ++;
		}
		else
			i++;
	}
	return (split[index] = NULL, split);
}
