/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:35:05 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/14 13:19:01 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_count_quotes(char * str)
{
	char quote;
	int i;
	int allocate;
	
	i = 0;
	if (!str || !ft_is_quote(str[i]))
		return (0);
	allocate = 0;
	quote = str[i];
	i ++;
	allocate ++;
	while (str[i])
	{
		if (str[i] == quote)
			return (allocate + 1);
		else
			i++;
		allocate ++;
	}
	return (allocate);
}

int	ft_count_metachar(char *str)
{
	int i;
	char meta_char;
	int allocate;
	
	i = 0;
	allocate = 0;
	meta_char = 0;
	if (!str || !ft_is_metachar(str[i]))
		return (0);
	meta_char = str[i];
	i ++;
	allocate ++;
	if (str[i])
	{
		if (meta_char == '>' && str[i] == '>')
			allocate ++;
		else if (meta_char == '<' && str[i] == '<')
			allocate ++;
	}
	return (allocate);
}

int ft_count_space(char *str)
{
	int i;
	int allocate;
	i = 0;
	allocate = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]) || ft_is_metachar(str[i]))
			break;
		i ++;
		allocate ++;
	}
	return (allocate);
}

int	ft_count_alloc(char *str, int index)
{
	int allocate;

	if (!str)
		return (0);
	allocate = 0;
	if (ft_is_metachar(str[index]))
	{
		allocate = ft_count_metachar(str + index);
	}else if (ft_is_quote(str[index]))
	{
		allocate = ft_count_quotes(str + index);
	} else if (!ft_is_space(str[index]))
	{
		allocate = ft_count_space(str + index);
	}
	return (allocate);
}
