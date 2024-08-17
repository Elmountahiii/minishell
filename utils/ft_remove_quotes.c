/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:00:24 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 16:43:32 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_remove_quotes(char *str)
{
	char	*new_str;
	int		i;
	int		start;
	int		end;

	if (!str)
		return (NULL);
	start = 0;
	end = ft_strlen(str) - 1;
	if (str[start] == '\'' || str[start] == '\"')
		start++;
	if (str[end] == '\'' || str[end] == '\"')
		end--;
	new_str = malloc(sizeof(char) * (end - start + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		new_str[i] = str[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
