/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:25:21 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/11 16:29:51 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	ft_count_at(char *str, int *index)
{
	int len;
	if (!str)
		return (0);
	*index += 1;
	len = 0;
	if (str[*index] == '@')
		(*index)++;
	while(str[*index] && str[*index] != ' ' && str[*index] != '$')
	{
		(*index)++;
		len++;
	}
	return (len);
}

int ft_count_for_dollar(char *str, int *index)
{
	int len;
	if (!str)
		return (0);
	*index += 1;
	len = 1;
	if (str[*index] == '@')
		(*index)++;
	while(str[*index] && str[*index] != ' ' && str[*index] != '$')
	{
		(*index)++;
		len++;
	}
	return (len);
}

int	ft_append_dollar(char *buffer, int *buffer_index, char *str, int *index)
{
	(void)buffer;
	(void)buffer_index;
	(void)str;
	(void)index;
	
	int len;
	(void)len;
	if (!str)
		return (0);
	
	return (1);
}


