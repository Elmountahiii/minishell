/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_expand_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:11:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/18 13:51:00 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_keys_count(char *value)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (value && value[i])
	{
		if (value[i] == '$')
			count++;
		i++;
	}
	return (count);
}

void	init_values(int *i, int *index)
{
	*i = 0;
	*index = 0;
}

char	**ft_split_keys(char *value)
{
	char	**keys;
	int		i;
	int		index;

	keys = ft_calloc(ft_keys_count(value) + 1, sizeof(char *));
	if (!keys)
		return (NULL);
	init_values(&i, &index);
	while (value && value[i])
	{
		if (value[i] == '$')
		{
			i++;
			if (!value[i])
			{
				keys[index++] = ft_strdup("$");
				break ;
			}
			keys[index] = ft_extract_key(&value[i]);
			i += ft_strlen(keys[index++]);
		}
		else
			i++;
	}
	return (keys[index] = NULL, keys);
}
