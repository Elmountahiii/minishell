/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:30:30 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/12 14:42:15 by yel-moun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	ft_allocate(char ***split, char *str)
{
	*split = malloc(sizeof(char *) * (ft_count_words(str) + 1));
	if (!(*split))
		return (1);
	return (0);
}

char	**ft_split(char *str)
{
	char	**split;
	int		index;
	int		i;

	if (ft_allocate(&split, str))
		return (NULL);
	i = 0;
	index = 0;
	while (str && str[i])
	{
		if (str[i] && (ft_is_quote(str[i]) || !ft_is_space(str[i])))
		{
			split[index] = ft_substr(str, i);
			if (!split[index])
				return (ft_free_split(split, index), NULL);
			index ++;
			if (str[i] && ft_is_quote(str[i]))
				i = ft_skip_quotes(str, i);
			else if (str[i] && !ft_is_space(str[i]))
				i = ft_skip_space(str, i);
		}
		else
			i++;
	}
	return (split[index] = NULL, split);
}

static int	ft_allocate_v2(char ***split, char *str)
{
	*split = malloc(sizeof(char *) * (ft_count_words_v2(str) + 1));
	if (!(*split))
		return (1);
	return (0);
}

char	**ft_super_split(char *str)
{
	char	**split;
	int		index;
	int		i;

	if (ft_allocate_v2(&split, str))
		return (NULL);
	i = 0;
	index = 0;
	while (str && str[i])
		i ++;
	return (split[index] = NULL, split);
}
