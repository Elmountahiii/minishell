/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:33:24 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/04 12:51:41 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_key_value(char *key ,char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strnstr(env[i], key, ft_strlen(key)))
			return (ft_strchr(env[i], '='));
		i ++;
	}
	return (NULL);
}
int	ft_count_expand_alloc(char *str, char **env, char **keys)
{
	int	i;
	int	count;
	int index;

	i = 0;
	count = 0;
	index = 0;
	while (str && str[i])
	{
		if (str[i] == '$')
		{
			i ++;
			while (str[i] && is_valid_expand(str[i]))
				i++;
			count += ft_strlen(ft_get_key_value(keys[index], env));
			index++;
		}
		else
		{
			count ++;
			i++;
		}
	}
	return (count);
}
