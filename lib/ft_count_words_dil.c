/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_dil.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:40:32 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/29 12:56:49 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_count_words_dil(char *str, char dil)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str && str[i])
	{
		if (str[i] != dil)
		{
			while (str[i] && str[i] != dil)
				i++;
			words ++;
		}
		else
			i++;
	}
	return (words);
}
