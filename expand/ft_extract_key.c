/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:29:18 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 19:54:23 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int ft_is_env_char(char c)
{
	if (c == ' ' || c == '@' || c == '-' || c == '.' || c == '$')
		return (1);
	return (0);
}

char	*ft_extract_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] && !ft_is_env_char(str[i]))
		i++;
	if (i == 0)
		return (NULL);
	key = ft_calloc(i + 1, sizeof(char));
	if (!key)
		return (NULL);
	i = 0;
	while (str[i] && !ft_is_env_char(str[i]))
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}
