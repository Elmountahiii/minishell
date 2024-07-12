/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:00:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/12 16:37:16 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_skip_space(char *str, int index)
{
	while (str[index] && !ft_is_space(str[index]))
		index ++;
	return (index);
}
int	ft_skip_space_v2(char *str, int index)
{
	while (str[index] && !ft_is_space_v2(str[index]))
		index ++;
	return (index);
}

int	ft_shift_from_quote(char *str, int index)
{
	while (str[index] && !ft_is_quote(str[index]))
		index ++;
	return(index);
}

int	ft_shift_space(char *str, int index)
{
	// bool quote = false;
	// if (str[index] == '\'' || str[index] == '\"')
	// {
	// 	quote = !quote;
	// 	index ++;
	// }
	// while (str[index])
	// {
	// 	if (!quote)
	// 	{
	// 		if (ft_is_quote(str[index]))
	// 		{
	// 			index = ft_shift_from_quote(str, index);
	// 			quote = !quote;
	// 		}
	// 		else if (!ft_is_space(str[index]) && !ft_is_metachar(str[index]))
	// 			index ++;
	// 		else
	// 			break;
	// 	}
	// 	else if (quote)
	// 	{
	// 		index ++;
	// 		if (str[index] == '\'' || str[index] == '\"')
	// 		{
	// 			index ++;
	// 			break;
	// 		}

	// 	}
	// 	else
	// 		break;
	// }
	// return (index);
	while (str[index] && !ft_is_space(str[index]))
	{
		if (ft_is_metachar(str[index]))
			break;
		printf("index : %d\n", index);
		index ++;
	}
	return (index);
}