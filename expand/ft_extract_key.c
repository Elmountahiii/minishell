/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:29:18 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 16:45:01 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_extract_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] && str[i] != '$' && str[i] != ' ' && str[i] != '-')
		i++;
	key = ft_calloc(i + 1, sizeof(char));
	if (!key)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '$' && str[i] != ' ' && str[i] != '-')
	{
		
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}
