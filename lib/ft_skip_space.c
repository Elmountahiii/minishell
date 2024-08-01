/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:00:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/29 11:24:59 by yel-moun         ###   ########.fr       */
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
	return (index);
}

int	ft_shift_space(char *str, int index)
{
	while (str[index] && !ft_is_space(str[index]))
	{
		if (ft_is_metachar(str[index]))
			break ;
		printf("index : %d\n", index);
		index ++;
	}
	return (index);
}
