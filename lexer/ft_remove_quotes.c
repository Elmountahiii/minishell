/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:36:41 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/07 10:44:32 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_remove_quotes(char *str)
{
	int j;
	int len;
	int i;
	char *new_str;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 1;
	j = 0;
	while (i < (len -1) &&  str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;	
	}
	new_str[j] = '\0';
	return (new_str);
}