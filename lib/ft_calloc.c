/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:11:14 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/21 10:20:20 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*obj;

	len = count * size;
	obj = malloc(len);
	if (!obj)
	{
		return (NULL);
	}
	ft_bzero(obj, len);
	return (obj);
}
