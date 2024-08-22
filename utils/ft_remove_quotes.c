/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:00:24 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/22 21:13:40 by yel-moun         ###   ########.fr       */
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

int	ft_has_any_quotes(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			return (1);
		str++;
	}
	return (0);
}

char	get_first_quote(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			return (*str);
		str++;
	}
	return (0);
}

char	*ft_remove_all_quotes(char *str)
{
	char	*new_str;
	int		i;
	int		j;
	char	quote;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	quote = get_first_quote(str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == quote)
			i++;
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}
